/* Copyright 2021 @ KindleStar (https://www.KindleStar.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

led_config_t g_led_config = {{
        {0,     1,        2,        3,      4,       5,       6,       7,        8,        9,                10,       11,     12,        13,         14},
        {15,    16,       17,       18,     19,      20,      21,      22,       23,       24,               25,       26,     27,     28, 29},
        {32,    33,       34,       35,     36,      37,      38,      39,       40,       41,               42,       43,     44,        45,         46},
        {47,    48,       49,       50,     51,      52,      53,      54,       55,       56,               57,       58,  59,60, 61},
     {64, 67,       68,      69,      70,      71,      72,      73,       74,       75,               76,    77,78,79,  80},
        {83,    84,       85,                    86, 87, 88,            89,       90,       91,               92,       93,     94}
},
{
// x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION
// y = 64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION


      {0, 0}, {15,0},  {31, 0}, {46, 0},  {62, 0}, {77, 0}, {92, 0}, {108, 0}, {123, 0}, {138, 0},           {154,  0},{169, 0},{184, 0},    {207, 0},        {214, 0},
      {0, 11},{15,11}, {31, 11},{46, 11}, {62,11}, {77,11}, {92,11}, {108,11}, {123, 11},{138, 11},          {154, 11},{169,11},{184,11},     {207,11},         {214,11},
      {0, 21},{15,21}, {31, 21},{46, 21}, {62,21}, {77,21}, {92,21}, {108,21}, {123, 21}, {138, 21},         {154, 21},{169,21},{184,21},     {207, 21},        {214, 21},
      {0, 31},{15,31}, {31, 31},{46, 31}, {62,31}, {77,31}, {92,31}, {108,31}, {123, 31},{138, 31},          {154, 31},{169,31},{184,31},      {207,31},         {214, 31},
      {0, 42},{15,42}, {31, 42},{46, 42}, {62,42}, {77,42}, {92,42}, {108,42}, {123, 42}, {138, 42},         {154, 42},{169,42},{184,42},      {207,42},        {214, 42},
      {0, 53},{15,53}, {31, 53},{46, 53}, {62,53}, {77,53}, {92,53}, {108,53}, {123, 53}, {138, 53},         {154, 53},{169,53},{184,53},      {207, 53},       {214, 53}
},
{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1
}};
