## Best Time to Buy and Sell Stock

### Условие
You are given an array `prices` where `prices[i]` is the price of a given stock on the i-th day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


### Ограничения
- $1 <= prices.length <= 10^5$
- $0 <= prices[i] <= 104$

### Решение
Допустим мы хотим продать акции в день `i`, тогда для того, 
чтобы найти максимально возможную прибыль нужно знать минимальную стоимость акции
в дни с `0` по `i-1`, т.е. минимум на префиксе `prices[0:i]`. Если минимум больше
сегодняшней цены, то выгоды не будет, а если меньше, то разность этих значений даст
максимально возможную прибыль. Т.о. если мы возьмем максимум возможной прибыли по всем
дням, то это и будет ответом. Решение реализует эту идею. Проходим по массиву и на каждом
шаге храним минимум на префиксе и текущую максимальную прибыль. Если текущее значение
меньше минимума, то обновляем минимум. Иначе считаем возможную прибыль и сравниваем с
максимально возможной прибылью на префиксе, если текущая больше, то обновляем. Максмально
возможная прибыль на префиксе `prices[0:prices.size()]` и будет ответом, который мы возвращаем.
