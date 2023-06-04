# OSvirtualDisk
操作系统大作业
## 1.文件系统组织方式：
#### ·使用磁盘块为基础单位，一个虚拟磁盘含有两种类型的磁盘块。
#### ·对于目录树和文件，统一采用磁盘块链的方式储存。
#### ·对于每一个磁盘块，有块头部份（24B）和块内容部分（1000B）。
#### ·其中块头部份储存了本块的类型：{目录块，文件块}，前一个块的位置，后一个块的位置；
### 1.1.目录块
#### ·目录块是磁盘目录树在磁盘的存储形式，每一个目录块包含25条记录：
#### ·每一条记录表示一个文件或者目录，其属性为：{父目录，文件/目录名称，文件的第一个文件块位置（如果不是是文件则为-1）}
#### ·通过广度优先算法将内存中的目录树转换为 vector<记录>，以25个为单位，拆分到目录块链中。
#### ·通过生成树算法将记录还原为内存中的目录树
### 1.2.文件块
#### ·每一个文件记录都会对应的分配至少一个文件块，文件内容以块链形式储存。


## 2.虚拟磁盘类

## 3.DOS类

## 4.主函数命令解析
