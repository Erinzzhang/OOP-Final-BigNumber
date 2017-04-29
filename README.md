# OOP-Final-BigNumber
## 大數乘法
- Karatsuba算法
>用於兩個大數的乘法，極大提高了運算效率，相較於普通乘法降低了複雜度，並在其中運用了遞歸的思想。<br>
基本的原理和做法是將位數很多的兩個大數 <I>x</I> 和 <I>y</I> 分成位數較少的數，每個數都是原來 <I>x</I> 和 <I>y</I> 位數的一半。<br>
這樣處理之後，簡化為做三次乘法，並附帶少量的加法操作和移位操作


![al](https://github.com/Erinzzhang/OOP-Final-BigNumber/blob/master/Karatsuba%E2%80%99s%20algorithm.png?raw=true "")
