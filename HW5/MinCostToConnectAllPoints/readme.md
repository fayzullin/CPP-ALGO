## Min Cost to Connect All Points

### Условие
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.


### Ограничения
- $1 <= points.length <= 1000$
- $-10^6 <= x_i, y_i <= 10^6$
- All pairs %(x_i, y_i)% are distinct.

### Решение
Соединим все точки друг с другои и получим полный граф.
Тогда исходная задача свелась к нахождению минимального остовного дерева для построенного графа.
Для построения миностова использовал алгоритм Прима для плотных графов, т.к. в нашем случае он полный.
Пояснения к алгоритму Прима не привожу, т.к. он базовый и был разобран на лекции.
