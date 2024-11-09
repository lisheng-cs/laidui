/*
 * @Descripttion: 
 * @Author: laidui
 * @version: 
 * @Date: 2024-11-09 16:43:04
 * @LastEditors: lai dui
 * @LastEditTime: 2024-11-09 16:46:37
 */
package org.example;

import java.math.BigInteger;
import java.sql.*;
import java.util.Arrays;
import java.util.Comparator;
public class Main {
    static Comparator<Integer> cmp = new Comparator<Integer>() {
        public int compare(Integer a, Integer b) {
            return b-a;
        }
    };
    public static void main(String[] args) throws SQLException {
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/test01", "root", "lisheng2003923");
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery("SELECT * FROM user");
        while(resultSet.next()){
            System.out.println(resultSet.getString("id") + " " + resultSet.getString("username") + " " + resultSet.getString("birthday"));
        }
    }
}