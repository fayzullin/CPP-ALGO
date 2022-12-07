## Coin Change

### Условие
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

### Ограничения
- $1 <= coins.length <= 12$
- $1 <= coins[i] <= 2^{31} - 1$
- $0 <= amount <= 10^4$

### Решение
Создаем массив, который будет содержать минимальное кол-во монет,
необходимое для получения суммы. Сумма - индекс в элемента массива, элемент - минимальное кол-во. Будем идти от начала и заполнять его.

Для получение нулевой суммы нужно ноль монет, остальные элементы 
инициализируем "бесконечностью".
Будем последовательно идти по элементам массива.
Для текущего элемента перебираем все монеты. 
Будем считать, что каждой сумме, а значит и каждому элементу 
`fewest_number`
соответствует некоторый набор монет `pack[curr_amount]`, который реализует указанное
в нем кол-во `fewest_number[i]`. Тогда текущая монета `coin` и `pack[curr_amount]` дают набор реализующий сумму `curr_amount + coin`, при этом кол-во монет равно 
`fewest_number[curr_amount] + 1`. Осталось сравнить полученное кол-во с тем, что уже записано в данный элемент массива и если получилось меньшее кол-во монет, то обновить значение массива. Т.к. при проходе по всем элементам мы перебираем все реализующие наборы, то в итоге получим минимальный набор (либо бесконечность, тогда вернем -1).