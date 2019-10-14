## 输入
```java
Scanner cin = new Scanner (System.in);
Scanner cin = new Scanner (new BufferedInputStream(System.in)); //快一点
a = cin.nextInt();
b = cin.nextDouble(); 
c = cin.nextBigInteger(); 
str = cin.nextLine(); //String，注意吃掉换行符
//高精度同理
//sc.close(); //不close虽然警告但是好像不影响结果
```
 
## 输出
```java
System.out.print(); // cout;
System.out.println(); // cout << … << endl;
System.out.printf(); // printf
```
### 示例
```java
public class Test
{
    public static void main(String[] args) 
    {
        int a; double b;
        a = 12345; b = 1.234567;
        System.out.println(a + " " + b);
        System.out.printf("%d %10.5f\n", a, b); 
        // 输入b为字宽为10，右对齐，保留小数点后5位，四舍五入.
    }
}
```

## 字符串

java中字符串String不可以修改，要修改只能转换为字符数组.
```java
public class Main
{
    public static void main(String[] args) 
    {
        int i;
        String st = "abcdefg";
        System.out.println(st.charAt(0)); // st.charAt(i)就相当于st[i].
        char [] ch;
        ch = st.toCharArray(); // 字符串转换为字符数组.
        for (i = 0; i < ch.length; i++) ch[i] += 1;
        System.out.println(ch); // 输入为“bcdefgh”.
        if (st.startsWith("a")) // 如果字符串以'a'开头.
        {
            st = st.substring(1); // 则从第1位开始copy(开头为第0位).
        }
    }
}
```
 

## 进制转换
```java
String st = Integer.toString(num, base);    // 把num当做10进制的数转成base进制的st(base <= 35).
int num = Integer.parseInt(st, base);   // 把st当做base进制，转成10进制的int(parseInt有两个参数,第一个为要转的字符串,第二个为说明是什么进制).   
BigInter m = new BigInteger(st, base);  // st是字符串，base是st的进制.
cin.nextBigInteger(2);  // 一个大数以2进制形式读入
cin.toString(2);    // 将它转换成2进制表示的字符串
```

### 示例 - 循环读入
 > b进制数p和m，p最大1000位，m最大10位。求p%m,并且用b进制表示
```java
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String[] args)
    {
        int b;
        BigInteger p,m,ans;
        String str ;
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
        while(cin.hasNext())
        {
            b=cin.nextInt();
            if(b==0) break;
            p=cin.nextBigInteger(b);
            m=cin.nextBigInteger(b);
            ans=p.mod(m);
            str=ans.toString(b);
            System.out.println(str);
        }
    }
}
```

## 高精度大数
### 基本操作
其实和int一样操作就可。
```java
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        
        BigInteger a = sc.nextBigInteger();
        BigInteger b = sc.nextBigInteger();
        BigInteger c = a.add(b);
        BigInteger d = a.multiply(b);

        System.out.println(a.mod(b)); //取模
        System.out.println(a.gcd(b)); //gcd
        System.out.println(a.pow(5)); //pow参数必须是int
        System.out.println(a.compareTo(b));
        System.out.println(a.equals(b));
        System.out.println(c);
        sc.close();
    }
}
```
### 初始化
```java
BigInteger ans = BigInteger.ZERO;
BigInteger fac = BigInteger.ONE;
```
### int转大数
```java
fac = fac.multiply(BigInteger.valueOf(i));
```

## 高精度小数

### 基本操作
大致同BigInteger。  
默认的toString()有些情况是科学记数法，用toPlainString()  
**除法必须考虑除不尽的情况**
```java
a.divide(b,5,BigDecimal.ROUND_HALF_UP);// a/b保留5位小数，version9后不推荐
```
#### 舍入方式
1. ROUND_UP：向上取整，远离零方向。
2. ROUND_DOWN：向下取整。趋向零方向。
3. ROUND_CEILING：向正无穷方向舍入。
4. ROUND_FLOOR：向负无穷方向舍入。
5. HALF_UP：四舍五入。
6. HALF_DOWN：四舍六入。
7. HAIL_EVEN：四舍六入五偶舍。在重复进行一系列计算时，此舍入模式可以将累加错误减到最小。
8. ROUND_UNNECESSARY/：精确保留不舍入
```java
bd1.setScale(15, BigDecimal.ROUND_DOWN); // version9后不推荐
```
### 字符串构造
```java
String temp1 = "1.00000000000000000000000000";
BigDecimal bd1 = new BigDecimal(temp1);
System.out.println(bd1.add(bd2).doubleValue()); // 转double，16位，最后一位不精确
```
加减乘除精度取最长