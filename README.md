# OSvirtualDisk
操作系统大作业：基于磁盘块链的文件系统实现

<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="知识共享许可协议" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />本作品可采用<a rel="license" href="http://creativecommons.org/licenses/by/4.0/">知识共享署名 4.0 国际许可协议</a>进行许可。

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
#### ·文件快的内容部分用于储存文件的内容

## 2.虚拟磁盘类

### 2.1 数据成员：
#### ·1个fstream对象，用于操作虚拟磁盘的文件内容
#### ·最小编号可用快，用于为writeIndex/writeBlock找不到下一个磁盘快时分配下一个磁盘块
#### ·\*blockStatus，用于记录磁盘所有块的使用状态

### 2.1 成员函数：
虚拟磁盘的成员函数直接为DOS类的增删改查服务
#### 基础操作：writeBlock(BlockNum)，readBlock(BlockNum)，clearBlocks(firstBlockNum)
#### 目录操作：writeIndex(firstBlockNum,indexList)，readIndex(firstBlockNum)
#### 文件操作：writeFile(firstBlockNum,fileContent)，readFile(firstBlockNum)

## 3.DOS类
负责将解析后的用户命令转换为对虚拟磁盘的查询，更改
#### ·string fullPath();返回当前目录全路径名称
#### ·int ls();列出当前目录下所有文件和目录
#### ·int help(string command="");打印命令说明
#### ·int cd(string);更改当前操作目录

#### ·int mkdir(string);创建文件夹
#### ·int rm(string);递归删除文件夹，删除文件

#### ·int cat_r(string);读文件
#### ·int cat_w(string, vector<char> & ); 写文件（覆盖）
#### ·int cat_a(string, vector<char> & ); 写文件（尾部增加）
	
## 4.主函数命令解析
### ·通过getline()读入一行命令，以空格为分隔符解析到vector<string>数组中。
### ·解析命令，调用对应DOS函数
