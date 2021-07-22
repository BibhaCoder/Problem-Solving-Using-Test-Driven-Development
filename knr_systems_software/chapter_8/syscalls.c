/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "syscalls.h"


main()  /* copy input to output */

{

    char buf[BUFSIZ];

    int n;


    while ((n = read(0, buf, BUFSIZ)) > 0)

        write(1, buf, n);

    return 0;

}

