## Islands Number

### Условие
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

### Решение
Будем помечать посещенные участки суши $'2'$.

Проходим по всем ячейкам и если встретили непосещенную сушу, то это новый остров.
Когда встречаем новый остров обходим его рекурсивно (DFS) и помечаем участки посещенными, по сути обходим весь остров.

По сути остров - это компонента связности в графе, которую мы обходим обходом в глубину
и нам нужно посчитать кол-во компонент связности.