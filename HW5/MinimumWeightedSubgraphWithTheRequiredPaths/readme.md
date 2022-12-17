## Minimum Weighted Subgraph With the Required Paths

### Условие
You are given an integer n denoting the number of nodes of a weighted directed graph. The nodes are numbered from 0 to n - 1.

You are also given a 2D integer array edges where $edges[i] = [from_i, to_i, weight_i]$ denotes that there exists a directed edge from fromi to toi with weight weighti.

Lastly, you are given three distinct integers $src_1$, $src_2$, and dest denoting three distinct nodes of the graph.

Return the minimum weight of a subgraph of the graph such that it is possible to reach dest from both src1 and src2 via a set of edges of this subgraph. In case such a subgraph does not exist, return -1.

A subgraph is a graph whose vertices and edges are subsets of the original graph. The weight of a subgraph is the sum of weights of its constituent edges.


### Ограничения
- $3 <= n <= 10^5$
- $0 <= edges.length <= 10^5$
- $edges[i].length == 3$
- $0 <= from_i, to_i, src_1, src_2, dest <= n - 1$
- $from_i \neq to_i$
- $src_1$, $src_2$, and $dest$ are pairwise distinct.
- $1 <= weight[i] <= 10^5$

### Решение
Решение использует алгоритм Дейкстры. Ввиду того, что алгоритм базовый, 
разбирался на лекции и легко гуглится, описывать его и доказывать корректность не буду.
Отмечу лишь, что ввиду ограничений пришлось реализовать вариант на `set`,
где операции релаксации и нахождения вершины с наименьшим текущим расстоянием
выполняются за логарифм от количества вершин.

Для решения задачи запускаем алгоритм Дейкстры для $src_1$, $src_2$ и $dest$ (над инвертированным графом).
Далее проходим по всем вершинам и минимум суммы расстояний от вышеуказанных вершин будет ответом.
Обобзначим пути от вершин $src_1$, $src_2$ до $dest$ $P_1$ и $P_2$ сответственно.
В искомом подграфе пути $P_1$ и $P_2$ в какой-то момент придут в общую вершину (возможно $dest$),
после чего остатки путей совпадают, т.к. в противном случае вес подграфа можно уменьшить.
При этом остаток нужно считать единожды при подсчете веса подграфа. Т.о. алгоритм перебирает
все вершины в качестве кандидата на общую вершину, т.о. перебираются все возможные кандидаты (подграфы)
и из них выбирается подграф с наименьшим весом.