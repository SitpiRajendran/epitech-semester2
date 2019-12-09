/*
** EPITECH PROJECT, 2019
** yes
** File description:
** yes
*/

#include "crocus.h"
#include <criterion/criterion.h>
#include <stdlib.h>

Test(print_while, rtn)
{
    cr_assert(print_while(NULL, NULL) == 84);
}

Test(printnum, rtn)
{
    cr_assert(printnum_nine(0, 24) == 84);
    cr_assert(printnum_eight(0, 24) == 84);
    cr_assert(printnum_seven(0, 24) == 84);
    cr_assert(printnum_six(0, 24) == 84);
    cr_assert(printnum_five(0, 24) == 84);
    cr_assert(printnum_four(0, 24) == 84);
    cr_assert(printnum_three(0, 24) == 84);
    cr_assert(printnum_two(0, 24) == 84);
    cr_assert(printnum_one(0, 24) == 84);
    cr_assert(printnum_zero(0, 24) == 84);
}

Test(init_line, rtn)
{
    cr_assert(init_line_3(NULL) == 84);
    cr_assert(init_line_4(NULL) == 84);
    cr_assert(init_line_5(NULL) == 84);
    cr_assert(init_line(NULL) == 84);
}

Test(freeall, rtn)
{
    cr_assert(freeall(NULL) == 84);
}

Test(get_letter, rtn)
{
    cr_assert(get_letter("unit_test", 2) == 'i');
}
