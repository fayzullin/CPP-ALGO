## Single Number III

### Условие
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

### Ограничения
- $2 <= nums.length <= 3 * 10^4$
- $-2^31 <= nums[i] <= 2^31 - 1$

### Решение
Для начала рассмотрим задачу, когда в массиве есть только одно число без пары.
С учетом того, что операция XOR коммутативна и ассоциативна, а также с учетом того, что 
`a XOR a == 0`, получаем, что искомое число в таком случае - XOR всех элементов.

Теперь рассмотрим нашу задачу, где два непарных числа. XOR всех чисел равен XOR-у
двух искомых чисел, т.к. они неравны, то у результирующего значения будет ненулевой бит,
т.е. у искомых чисел этот бит отличается. Теперь можно разделить все числа
на две группы, в зависимости от значения этого бита. Если в этих группах сделать XOR
всех чисел, то получим искомые числа. 
