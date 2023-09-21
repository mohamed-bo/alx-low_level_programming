          global    main
          extern    printf
main:
	  mov   edi, prr
	  xor   eax, eax
	  call  printf
	  mov 	eax, 0
	  ret
prr: db `Hello, Holberton\n`,0
