## 2.1 序列傅里叶变换

### 时域离散信号傅立叶变换 (DTFT) 的定义

1. 采样信号

    数学表示：
    $$
    \hat x_a(t) = \sum\limits_{n=-\infin}^{\infin}x_a(nT)\delta(t-nT)
    $$
    傅立叶变换：
    $$
    \hat X_a(j\Omega) = \int_{-\infin}^\infin \hat x_a(t) e^{-j\Omega t} dt  \\
    
    = \int_{-\infin}^\infin [\sum\limits_{n=-\infin}^{\infin}x_a(nT)\delta(t-nT)] e^{-j\Omega t}dt
    \\
    
    =\sum\limits_{n=-\infin}^{\infin}[x_a(nT)e^{-j\Omega nT}\int_{-\infin}^{\infin}\delta(t-nT)dt]\\
    
    =\sum\limits_{n=-\infin}^{\infin}x_a(nT)e^{-j\Omega nT}
    $$
    令 $x_a(nT) = x(n),~\Omega T = \omega$，用 $X(e^{j\omega})$ 来表示 $\hat X_a (j\Omega)$，得到傅立叶变换 (FT) 的定义：
    $$
    X(e^{j\omega}) = \sum\limits_{n=-\infin}^{\infin}x(n)e^{-j\omega n}
    $$
    序列傅立叶变换存在的条件：
    $$
    \sum\limits_{n=-\infin}^{\infin} |x(n)| < \infin
    $$
    序列的傅立叶反变换 (IFT) ：
    $$
    x(n) = \frac{1}{2 \pi} \int_{-\pi}^\pi X(e^{j\omega}) e^{j\omega n} d\omega
    $$

2. 典型序列的傅立叶变换

    - $\delta(n)$ 
        $$
        X(e^{j\omega}) = \sum\limits_{n=-\infin}^{\infin} \delta(n)e^{-j\omega n}
        $$
        由于 $\delta(n)x(n) = x(0)\delta(n)$
        $$
        \text{上式} = \sum\limits_{n=-\infin}^\infin \delta(n) = 1
        $$

    - $a^n u(n) ~(0 < a < 1)$ 
        $$
        X(e^{j\omega}) = \sum\limits_{-\infin}^{\infin} a^n u(n) e^{-j\omega n} \\
        
        = \sum\limits_{n=0}^\infin a^ne^{-j\omega n} \\
        
        = \sum\limits_{n=0}^\infin (ae^{-j\omega})^n \\
        
        = \frac{1}{1 - ae^{-j\omega}}
        $$

### 时域离散信号傅立叶变换的性质

1. 周期性
    $$
    X(e^{j\omega}) = \sum\limits_{n = -\infin}^\infin x(n) e^{-j\omega n} \\
    
    = \sum\limits_{n = -\infin}^\infin x(n) e^{-j(\omega + 2\pi M)n} \\
    
    = X(e^{j(\omega + 2\pi M)})
    $$

2. 线性

    设 $FT[x_1(n)] = X_1(e^{j\omega}),~FT[x_2(n)]=X_2(e^{j\omega})$
    $$
    FT(ax_1(n) + bx_2(n)) = aX_1(e^{j\omega}) + bX_2(e^{j\omega})
    $$

3. 时移与频移性质

    设 $FT[x(n)] = X(e^{j\omega})$
    $$
    \begin{align}
    \text{时移：}&FT[x(n-n_0)] = e^{-j\omega n_0} X(e^{j\omega}) \\
    \text{频移：}&X(e^{j(\omega - \omega_0)}) =FT[e^{j\omega_0 n} x(n)]
    \end{align}
    $$

4. 时域卷积性质
    $$
    y(n) = x(n) * h(n) \\
    Y(e^{j\omega}) = X(e^{j\omega}) H(e^{j\omega})
    $$

5. 频域卷积性质
    $$
    y(n) = x(n)h(n) \\
    Y(e^{j\omega}) = \cfrac{1}{2\pi}X(e^{j\omega})*H(e^{j\omega})
    $$

6. 帕斯维尔定理（能量定理）
    $$
    \sum\limits_{n=-\infin}^\infin |x(n)|^2 = \frac{1}{2\pi} \int_{-\pi}^\pi |X(e^{j\omega})|^2 d\omega
    $$


## 2.2 序列傅立叶变换的对称性

### 复变函数基础

1. 复数的定义
    $$
    z = x + yj
    $$
    
    实部与虚部：
    

    $$
    \begin{align}
    \text{实部：}& x = R_e(z)
    \\ \text{虚部：} & y = I_m(z)
    \end{align}
    $$

    复数的指数表示法：
    $$
    z = re^{j\omega}\\r=\sqrt{x^2+y^2}~~~~~~~~\theta=\arctan(\frac{y}{x})
    $$
    
1. 共轭复数
    $$
    z^* = x -yj ~~~~~~~~ z^* = re^{-j\theta}
    $$

3. $x(n)$ 的复数性质

    设 $x(n)$ 和其共轭 $x^*(n)$
    $$
    x(n) = x_r(n) + jx_i(n) \\
    x^*(n) = x_r(n) - jx_i(n)
    $$

### $x(n)$ 的相关变换

设 $FT[x(n)] = X(e^{j\omega})$

- $x(-n)$
    $$
    \begin{align}
    FT[x(-n)] &= \sum\limits_{n=-\infin}^\infin x(-n) e^{-j\omega n} \\
    &= \sum\limits_{n=-\infin}^\infin x(n)e^{j\omega n}  = X(e^{-j\omega})
    \end{align}
    $$

- $x^*(n)$
    $$
    \begin{align}
    FT[x^*(n)] &= \sum\limits_{n = -\infin}^\infin x^*(n) e^{-j\omega n}  \\
    &= [\sum\limits_{n = -\infin}^\infin x(n) e^{j\omega n}]^*  
    = X^*(e^{-j\omega})
    \end{align}
    $$

- $x^*(-n)$
    $$
    \begin{align}
    FT[x^*(-n)] &= \sum\limits_{n = -\infin}^\infin x^*(-n) e^{-j\omega n} 
    = [\sum\limits_{n = -\infin}^\infin x(-n) e^{j\omega n}]^*  
    \\ &= [\sum\limits_{n = -\infin}^\infin x(n) e^{-j\omega n}]^*  
    = X^*(e^{j\omega})
    \end{align}
    $$

总之，$-n$ 使得 $\omega$ 反折，$x^*$ 使得 $X^*$ 再反折 $\omega$ 

### $x(n)$ 分解的变换

对 $x(n)$ 分解为两个部分相加
$$
\begin{align}
\text{序列共轭对称部分：}
x_e(n) &= \frac{1}{2}[x(n) + x^*(-n)] \\

\text{序列共轭反对称部分：}
x_o(n) &= \frac{1}{2}[x(n)-x^*(-n)] \\
\end{align}
$$
可以得到
$$
x(n) = x_e(n) + x_o(n) \\
$$

考虑等号两边的傅里叶变换

**序列的共轭对称部分 对应 傅立叶变换的实部**
$$
FT[x_e(n)] = \frac{1}{2}[X(e^{j\omega}) + X^*(e^{j\omega})] = R_e[X(e^{j\omega})]
$$
**序列共轭反对称部分 对应 傅里叶变换的虚部（包括 $j$）**
$$
FT[x_o(n)] = \frac{1}{2}[X(e^{j\omega}) - X^*(e^{j\omega})] = jI_m[X(e^{j\omega})]
$$
那么等式左边的傅里叶变换可以分解成实部和虚部，分别由上述的序列的两个部分变换而来
$$
X(e^{j\omega}) = R_e[X(e^{j\omega})] + jI_m[X(e^{j\omega})]
$$


类似的，我们将序列分解为实部和虚部，即
$$
x(n) = R_e[x(n)] + jI_m[x(n)] 
$$
等式两边做傅里叶变换，可以得到（忽略证明过程）
$$
X(e^{j\omega}) = X_e(e^{j\omega}) + X_o(e^{j\omega})
$$
可以发现

**序列的实部 对应 傅立叶变换的共轭对称部分**

**序列的虚部 对于 傅立叶变换的共轭反对称部分**

### 对于实序列的结论

实序列的共轭就是其自身，则对于时序列的共轭和反共轭分解，就等价于奇偶对称的分解
$$
x_e(n) = \frac{1}{2}[x(n) + x(-n)] ~~\to~~ \text{偶分量} ~~\to~~ R_e[X(e^{j\omega})] \text{ 偶对称} \\
x_o(n) = \frac{1}{2}[x(n) - x(-n)]
~~ \to ~~ \text{奇分量} ~~\to~~I_m[X(e^{j\omega})] \text{ 奇对称}
$$

- 频域函数实部是关于 $\omega$ 的偶函数，虚部（含 $j$ ) 是奇函数

- 实部偶对称，虚部奇对称
    $$
    \begin{align}
    R_e[X(e^{j\omega})] &= R_e[X(e^{-j\omega})] \\
    I_m[X(e^{j\omega})] &= - I_m[X(e^{-j\omega})]
    \end{align}
    $$

- 模偶对称，幅角奇对称
    $$
    \begin{align}
    |X(e^{j\omega})| &= |X(e^{-j\omega})| \\
    \arg [X(e^{j\omega})] &= - \arg [X(e^{-j\omega})]
    \end{align}
    $$

## 2.3 序列的 $z$ 变换

### $z$ 变换的定义

定义一个复数自变量 $z$
$$
z = e^{j\omega}
$$
代入序列傅立叶变换公式
$$
X(z) = \sum\limits_{n=-\infin}^\infin x(n)z^{-n}
$$

### 典型序列的 $z$ 变换

求收敛域的时候，等比级数求和公比绝对值小于 $1$

- $\delta(n)$
    $$
    \begin{align}
    X(z) &= \sum\limits_{n=-\infin}^\infin \delta(n)z^{-n} \\
    &= \sum\limits_{-\infin}^\infin \delta(n) = 1~~~~~~~~~~~~~0<|z|<\infin
    \end{align}
    $$

- $u(n)$
    $$
    \begin{align}
    X(z) &= \sum\limits_{-\infin}^\infin u(n)z^{-n} \\
    &= \sum\limits_{n=0}^\infin z^{-n} = \frac{1}{1-z^{-1}}~~~~~~~~~~~~|z|>1
    \end{align}
    $$

- $R_4(n)$
    $$
    \begin{align}
    X(z) &= \sum\limits_{n=-\infin}^\infin R_4(n)z^{-n} \\
    &= \sum\limits_{n=0}^3 z^{-n} = \frac{1-z^{-4}}{1-z^{-1}}~~~~~~~~~~~0<|z|<\infin
    \end{align}
    $$

- $a^nu(n)$
    $$
    \begin{align}
    X(z) &= \sum\limits_{n=-\infin}^\infin a^nu(n)z^{-n} = \sum\limits_{n=0}^{\infin}a^n z^{-n}\\
    & =\sum\limits_{n=0}^\infin (az^{-1})^n = \frac{1}{1-az^{-1}}~~~~~~~~|z|>a
    \end{align}
    $$

- $a^nu(-n)$
    $$
    \begin{align}
    X(z) 
    &= \sum\limits_{n=-\infin}^\infin a^n u(-n) z^{-n} 
     = \sum\limits_{n=-\infin}^0 a^n z^{-n} \\
    &= \sum\limits_{n=0}^\infin (a^{-1}z)^n = \frac{1}{1-a^{-1}z}~~~~~~~~|z|<a
    \end{align}
    $$

- 

### 序列特征对收敛域的影响

| 序列类型   |       收敛域        |
| ---------- | :-----------------: |
| 有限长序列 |   $0<|z|<\infin$    |
| 右边序列   |       $|z|>a$       |
| 左边序列   |      $|z| < a$      |
| 双边序列   | $R_{x-}<|z|<R_{x+}$ |

## 2.4 $z$ 变换的性质

1. 线性

    设 $x_1(n) \leftrightarrow X_1(z)$, $x_2(n)\leftrightarrow X_2(z)$
    $$
    ax_1(n)+bx_2(n)~\leftrightarrow~ aZ_1(z) + bX_2(z)
    $$
    注意讨论收敛域，一般会发生改变

2. 序列移位性质

    设 $x(n) \leftrightarrow X(z)$

    - $x(n)$ 为双边序列
        $$
        x(n\pm n_0) \leftrightarrow z^{\pm n_0}X(z)
        $$
        不改变 $z$ 变换的收敛域

    - $x(n)$ 为右边序列

        注意有初始值代入

        - 右移
            $$
            \begin{align}
            x(n - 1) &\leftrightarrow z^{- 1}X(z) + x(-1) \\
            x(n - 2) &\leftrightarrow z^{- 2}X(z) + z^{-1}x(-1) - x(-2) \\
            &\cdots \\
            x(n - m) &\leftrightarrow z^{-m}X(z) + \sum\limits_{i = m-1}^{0}z^{-i}x(i-m)
            \end{align}
            $$

        - 左移
            $$
            \begin{align}
            x(n + 1) &\leftrightarrow z^{1}X(z) - x(1) \\
            x(n + 2) &\leftrightarrow z^{2}X(z) - z^{1}x(1) - x(2) \\
            &\cdots \\
            x(n + m) &\leftrightarrow z^{m}X(z) - \sum\limits_{i = m-1}^{0}z^{i}x(m-i)
            \end{align}
            $$
            

        

