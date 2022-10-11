## Generate Parentheses

### Условие
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

### Ограничения
- $board.length == 9$
- $board[i].length == 9$
- $board[i][j] is a digit or '.'$
- $It is guaranteed that the input board has only one solution$

### Решение
В решении реализован рекурсивный алгоритм поиска решения судоку.

Будем идти от левого верхнего края к правому нижнему.

Ищем следующую пустую клетку, ставим туда первое подходящее число от 1 до 9 (проверки для строки, для столбца и для подтаблицы), ищем следующую пустую клетку и идем в начало алгоритма. Если на этапе подбора числа не смогли подобрать его, то идем на предыдующий шаг и берем следующее число.
В какой-то момент там окажется правильное число и к нему мы уже не вернемся.
