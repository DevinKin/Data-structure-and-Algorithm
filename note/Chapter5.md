# 第5章-散列

- 散列表的实现常常叫做散列（hashing）。
- 散列是一种用于以常数平均时间执行插入、删除和查找的技术。

## 一般想法

- 每个关键字被映射到从0到TableSize-1这个范围中的个数，并且被放到适当的单元中。这个映射就叫做散列函数（hash function），理想情况下它应该运算简单并且应该保证任何两个不同的关键字映射到不同的单元。

## 散列函数

- 如果输入的关键字是整数，则一般合理的方法就是直接返回`Key mod TableSize`的结果，除非Key碰巧具有某些不理想的性质。

- 若表的大小是10而关键字都是以0为个位，则冲突就会十分多。避免该情况，通常保证表的大小是素数。

- 一个简单的散列函数

  ```c
  int Hash(const char *key, int TableSize) {
      unsigned int HashVal  = 0;
      while (*key != '\0') {
          HashVal += *key++;
      }
      return HashVal % TableSize;
  }
  ```

- 另一种可能的散列函数——不太好

  ```c
  int Hash(const char *key, int TableSize) {
      return (key[0] + 27 * key[1] + 729 *key[2]) % TableSIze;
  }
  ```

- 一个好的散列函数

  ```c
  int Hash(const char *key, int TableSize) {
      unsigned int HashVal  = 0;
      while (*key != '\0') {
          HashVal = (HashVal << 5) + *key++;
      }
      return HashVal % TableSize;
  }
  ```

- 解决散列值相同的方法

  - 分离链接法。
  - 开放定址法。

## 分离链接法

- 分离链接法（separate chaining），其做法就是将散列到同一个值的所有元素保留到一个表中。
- 定义散列表的填装因子（load factor）$\lambda$为==散列表中的元素个数==与==散列表大小的比值==。
- 执行一次查找所需要的工作是计算散列函数值所需要的常数时间加上遍历表（list）所用的时间。
  - 在一次不成功的查找中，遍历的链接平均为$\lambda$（不包括最后的NULL）链接。
  - 在一次成功的查找中，遍历的链接数大约为$1 + (\lambda/2)$。

