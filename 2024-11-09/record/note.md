# 第十六届全国大学生数学竞赛辽宁赛区


# JDBC(Java Database Connection)


JDBC（Java Database Connectivity）是Java数据库连接技术的简称，它是一套用于执行SQL语句的Java API。JDBC为多种关系型数据库提供了统一的访问方式，它使得Java程序能够与数据库进行交互，执行SQL语句，包括查询、更新、插入和删除等操作。

JDBC的主要功能包括：

1. **建立数据库连接**：通过JDBC驱动程序与数据库建立连接。
2. **执行SQL语句**：执行SQL查询、更新、插入和删除等操作。
3. **处理结果**：对查询结果进行处理，如获取查询结果集。
4. **事务管理**：支持事务的提交和回滚。
5. **资源管理**：管理数据库连接、语句和结果集等资源。

JDBC API通常包括以下几个核心接口和类：

- `DriverManager`：用于管理JDBC驱动程序，并创建数据库连接。
- `Connection`：代表与特定数据库的连接。
- `Statement`：用于执行静态SQL语句并返回它所生成结果的对象。
- `PreparedStatement`：继承自 `Statement`，用于执行参数化的SQL语句，可以提高性能和防止SQL注入攻击。
- `CallableStatement`：用于调用数据库中的存储过程。
- `ResultSet`：代表SQL查询的结果集，可以通过它检索和处理查询结果。

使用JDBC时，通常需要以下步骤：

1. 加载JDBC驱动程序。
2. 建立与数据库的连接。
3. 创建 `Statement`或 `PreparedStatement`对象。
4. 执行SQL语句。
5. 处理结果集。
6. 清理环境，关闭连接。

JDBC是Java数据库编程的基础，广泛应用于企业级应用开发中。
