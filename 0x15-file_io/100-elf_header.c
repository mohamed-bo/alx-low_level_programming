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
 * printElfInformation -print Elf file Information
 * @header: pointer to the header of elf file
 *
 * Description: If the file
 */

void printElfInformation(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x\n",
	       header->e_ident[EI_MAG0], header->e_ident[EI_MAG1],
	       header->e_ident[EI_MAG2], header->e_ident[EI_MAG3]);
	printf("  Class:                             %s\n",
		header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
		header->e_ident[EI_DATA] == ELFDATA2LSB ?
		"2's complement, little endian" :
		"2's complement, big endian");
	printf("  Version:                           %d (current)\n",
		header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
		header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
		"UNIX - System V");
	printf("  ABI Version:                       %d\n",
		header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
		header->e_type == ET_EXEC ? "EXEC (Executable file)" :
		"EXEC (Executable file)");
	printf("  Entry point address:               0x%lx (bytes into file)\n",
		header->e_entry);
	printf("  Start of program headers:          %lu (bytes into file)\n",
		header->e_phoff);
	printf("  Start of section headers:          %lu (bytes into file)\n",
		header->e_shoff);
	printf("  Flags:                             0x%x\n", header->e_flags);
	printf("  Size of this header:               %d (bytes)\n", header->e_ehsize);
	printf("  Size of program headers:           %d (bytes)\n",
		header->e_phentsize);
	printf("  Number of program headers:         %d\n", header->e_phnum);
	printf("  Size of section headers:           %d (bytes)\n",
		header->e_shentsize);
	printf("  Number of section headers:         %d\n", header->e_shnum);
	printf("  Section header string table index: %d\n", header->e_shstrndx);
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
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
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
