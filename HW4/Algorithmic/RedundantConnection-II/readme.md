## Redundant Connection II

### Условие
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.

Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

### Решение
Все входящие графы можно разбить на три типа:
1) некоторая вершина имеет степень 2 и нет цикла
2) нет вершины степени 2 и есть цикл
3) некоторая вершина имеет степень 2 и есть цикл

Разобьем алгоритм на два этапа.

На первом этапе найдем вершину степени 2, если таковая имеется. Направленные к ней ребра являются кандидатами на удаление.
При этом у последнего ребра вторую вершину заменим на фиктивную. Теперь у всех вершин степень 1.

На втором этапе ищем цикл. Для этого проходим по всем ребрам и сравниваем родителя первой вершины ребра со второй, где под родителем
понимается родитель в структуре `disjoint union`. 

Рассмотрим все случаи.
- Есть цикл: проверяем есть ли кандидаты на удаление, 
  - нет кандидатов, значит граф типа 2 и нужно разорвать цикл, чтобы он стал корректным. По условию
  нужно удалить последнее входное ребро, что обеспечивается способом итерации по ребрам.
  - есть кандидаты, значит граф типа 3 и нужно разорвать цикл там, где находится вершина степени 2.
- Нет цикла: значит полученный граф валидный (все вершины степени не более 1). А значит мы "удалили" (заменили одну из вершин на фиктивную) искомое ребро.