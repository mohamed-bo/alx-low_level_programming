#include "main.h"
#include <elf.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)

/**
 * safeClose - safeClose
 * @file: The file
 *
 * Description: If the file
 */

void safeClose(int file)
{
	if (close(file) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", file);
		exit(98);
	}
}

/**
 * isElf - Checks if a file is ELF
 * @e_ident: array of the ELF magic numbers.
 *
 * Description: If the file
 */

void isElf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 ||
	    e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 ||
	    e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}

}

/**
 * print_type - print type of an ELF
 * @e_type: elf Type
 * @e_ident: elf classes
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - prints the entry point of ELF file
 * @e_entry: elf entry
 * @e_ident: elf classes
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * print_osabi - prints OS ABI
 * @e_ident: ELF version.
 */
void printOsAbi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * printElfInformation -print Elf file Information
 * @header: pointer to the header of elf file
 *
 * Description: If the file
 */

void printElfInformation(Elf64_Ehdr *header)
{
	char *s = header->e_ident[EI_VERSION] == EV_CURRENT ? " (current)\n" :
	"\n";
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", header->e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
	printf("  Class:                             %s\n",
		header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
		header->e_ident[EI_DATA] == ELFDATA2LSB ?
		"2's complement, little endian" :
		"2's complement, big endian");
	
	printf("  Version:                           %d%s",
		header->e_ident[EI_VERSION], s);
	printOsAbi(header->e_ident);
	printf("  ABI Version:                       %d\n",
		header->e_ident[EI_ABIVERSION]);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);
}

/**
 * main - displays the information contained in the ELF header.
 * @argc: size of arguments array
 * @argv: arguments array
 * Return: 0 on success,
 * 98 on fails
 */

int main(int argc, char *argv[])
{
	int file;
	Elf64_Ehdr *header;

	UNUSED(argc);
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		dprintf(STDERR_FILENO, "Error: '%s': No such file\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		safeClose(file);
		dprintf(STDERR_FILENO, "Error: Can't malloc %s\n", argv[1]);
		exit(98);
	}
	if (read(file, header, sizeof(Elf64_Ehdr)) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]);
		exit(98);
	}
	isElf(header->e_ident);
	printElfInformation(header);
	safeClose(file);
	return (0);
}
