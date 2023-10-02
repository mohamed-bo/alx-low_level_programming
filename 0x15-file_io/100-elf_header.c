#include "main.h"
#include <elf.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)

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
