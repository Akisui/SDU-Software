# Digital Signal Processing

##  1. Introduction to Signals

### 1.1 Characterization and Classification of Signals

- Continuous-time signal : $u(t)$

    $t$, second ---- continuous independent variable

    - with continuous-valued amplitudes : analog signal
    - with discrete-valued amplitudes : quantized boxcar signal

- Discrete-time signal : $\{v(nT)\}=\{v[n]\}$

    $n$ ---- discrete independent variable

    $T$, second ---- Sampling interval or sampling period

    $f_s=\cfrac{1}{T}$, Hz ---- Sampling frequency

    $v[n]$, each member ---- sample

    - with continuous-valued amplitudes : sample-data signal
    - with discrete-valued amplitudes : digital signal

​		*In this course, digital signal  is treated same as sample-data signal.*



### 1.2 The Presentation of General Digital Signal

- Enumeration form

$$
x[n] = \{...,x[-1],x[0],x[1],...\}
$$

- Convolutional form (time shift property)

$$
x[n]=\sum\limits_{m=-\infin}^\infin \delta[n-m]x[m] = \delta[n] \otimes x[n]
$$

- Using Euler's formula

$$
\begin{align}  
\cos(\omega_0 n + \phi) &+ j\sin(\omega_0 n + \phi) = e^{j(\omega_0 n + \phi)} \\
\cos(\omega_0 n + \phi) &= \Re(e^{j(\omega_0 n + \phi)}) = \frac{e^{j(\omega_0 n + \phi)} + e^{-j(\omega_0 n + \phi)}}{\small 2} \\
\sin(\omega_0 n + \phi) &= \Im(e^{j(\omega_0 n + \phi)}) = \frac{e^{j(\omega_0 n + \phi)} - e^{-j(\omega_0 n + \phi)}}{\small 2j}

\end{align}
$$

### 1.3 The presentation of DSP system

- General representation of DSP system

    - Differential form

         $\sum a_q \cdot y[n-q] = \sum b_p \cdot x[n-p]$

        - No-recursive form

            ex.  $y[n] = \large\frac{1}{1+m} \normalsize\sum\limits_{k=0}^m x[n-k]$

        - Recursive form

            ex.  $y[n] = y[n-1] + \large\frac{1}{1+m} \left( \normalsize x[n] - x[n-1-m] \large\right)$

    - Convolution form

        $y[n] = \sum b_p \cdot x[n-k] ~\to~ \sum\limits_{k=-\infin}^\infin h[k]x[n-k] ~\to~ \sum\limits_{k=-\infin}^\infin x[k]h[n-k]$

        ex.  $y[n] = \large\frac{1}{1+m} \normalsize\sum\limits_{k=0}^m x[n-k]$





## 2. Discrete-Time Signal and System in Time Domain



### 2.1 Time-Domain Representation



#### 2.1.1 Length of Discrete-Time Signal

- Finite-length sequence is defined only for a finite time interval
    $$
    N_1 \leq n \leq N_2~
    $$
    which also represented by
    $$
    x[n]\left(\mu[n - N_1] - \mu[n-N_2]\right)
    $$

- Infinite-length sequence has three types

    - Right-sided sequence $x[n]$ has zero-valued samples for $n < N_1$ , that is
        $$
        x[n] = 0 ~~~~~~\text{for} ~n<N_1
        $$
        which also represented as
        $$
        x[n]\mu[n-N_1]
        $$
        If $N_1≥ 0$ , a right-sided sequence usually is called a *causal sequence*.

    - Left-sided sequence $x[n]$ has zero-valued samples for $n > N_2$ , that is
        $$
        x[n] = 0 ~~~~~~\text{for} ~n>N_2
        $$
        which alse represented as
        $$
        x[n]\mu[-n-N_2]
        $$
        If $N_2 ≤ 0$ , a left-sided sequence  usually is called an *anticausal sequence* , likewise.
    
    - Two-sided sequence is defined for both positive and negative values of $n$ , that is
    
        $$
        -\infin  \leq n \leq N_2,~N_1 \leq n \leq \infin \\ \text{or}~~ -\infin \leq n \leq \infin
        $$
        which alse represented as
        $$
        x[n](\mu[n-N_1] + \mu[-n-N_2]) ~~ \text{or} ~~ x[n]
        $$



#### 2.1.2 Strength of a Discrete-Time Signal

The strength of a discrete-time signal usually is given by its norm. In general, the $\mathscr L _p$ - *norm* of a sequence $\{x[n]\}$ is defined by
$$
\|x\|_p = \left(\sum\limits_{n=-\infin}^{\infin} |x[n]|^p\right)^{1/p}
$$
 where the value of $p$ is typically $1$ or $2$ or $\infin$ .

- The $\mathscr L _\infin$ - norm is given by the *peak absolute value*, that is,
    $$
    \|x\|_\infin = |x|_{\text{max}}
    $$

- The $\mathscr L _1$ - norm is given by the *sum of the absolute values*, that is,
    $$
    \|x\|_1 = \sum\limits_{-\infin}^\infin |x[n]|
    $$
    $\Rightarrow$  *mean absolute value*  $=\cfrac{1}{N}\|x\|_1$

- The $\mathscr L _2$ - norm is given by the *sum of squared values*, that is,
    $$
    \|x\|_2 = \left(\sum\limits_{-\infin}^\infin |x[n]|^2\right)^{1/2}
    $$

​		$\Rightarrow$  *roo-mean-squared (rms)*  $=\cfrac{\|x\|_2}{\sqrt N}$

​		$\Rightarrow$  *mean square error (MSE)*  $= \cfrac{1}{N}\left(\|y[n] - x[n]\|_2\right)^2$

​			 used in estimating the error in the approximation, such as  *Maximum Likelihood Estimation*

​		$\Rightarrow$  *relative error (MSE)*  $= \cfrac{\|y[n] - x[n]\|_2}{\|x[n]\|_2}$ 



### 2.2 Operations on Sequences



#### 2.2.1 Elementary Operations

- Modulation (Product) - modulator
    $$
    w_1 = x[n] \cdot y[n]
    $$
    forming the *product* of the sample values of two sequences at each instant

    - Windowing

        forming a finite-length sequence from an infinite-length sequence

        by multipling the lattter with a finite-length swquence, which is called *window sequence*

- Scalar multiplication - multiplier 
    $$
    w_2 = Ax[n]
    $$
    multiplying each sample of a sequence by a scalar

- Addition & Subtractions

    $w_3 = x[n] + y[n]$

    - reduce noise

        improve the quality of measured data that has been corrupted by an additive random noise
        $$
        \bold x_i = \bold s + \bold d_i
        $$
        $\bold d_i$ denote the noise vector corrupting $i$-th measurement of $\bold s$
        $$
        \bold x_{\text{ave}} = \cfrac{1}{K}\sum\limits_{i=1}^K (\bold x_i) = 
        \cfrac{1}{K}\sum\limits_{i=1}^K (\bold s + \bold d_i) =
        \bold s + \cfrac{1}{K}\left(\sum\limits_{i=1}^K \bold d_i \right) \to \bold s
        $$
        the average data vector is called *ensemble average*

- Time-shifting
    $$
    w_4 = x[n-N]
    $$

    - $(N > 0)$  Delaying - unit delay

        For $N=1$ , we have
        $$
        w_4 = x[n-1]
        $$
        in terms of $z$ - transform, the above relation can be rewritten as
        $$
        W_4 = z^{-1} X(z)
        $$

    - $(N<0)$  Adcancing - unit advance

        For $N=1$ , we have
        $$
        w_5 = x[n+1]
        $$
        in terms of $z$ - transform, the above relation can be rewritten as
        $$
        W_5 = z~ X(z)
        $$

- Time-reversal
    $$
    w_6[n] = x[-n]
    $$

- Pick-off Node

    used to feed a sequence to different parts of a discrete-time system

If the sequences are not of equal length, *append zero-valued samples* to smaller guys.

*Elimentary operations could be cascaded.*



#### 2.2.2 Convolution Sum

The sequence $y[n]$ generated by the *convolution sum* of two sequence, $x[n]$ and $y[n]$, is given by
$$
y[n] = \sum\limits_{k=-\infin}^\infin x[k]h[n-k]
$$
which alternatively can be written as
$$
y[n] = \sum\limits_{k=-\infin}^\infin x[n-k]h[k]
$$
For brevity, the convolution sum will be compactly written as
$$
y[n] = x[n]\otimes h[n]
$$
In general, if the length of two sequences being convolves are $M$ and $N$, then the resulting sequence after convolution is of length $M+N-1$.

The convolution sum operation satisfies several properties, that is

|                 Property                 |                           Equation                           |
| :--------------------------------------: | :----------------------------------------------------------: |
|               commutative                |       $x_1[n] \otimes x_2[n] = x_2[n] \otimes x_1[n]$        |
| (when stable and single-sided) associate | $(x_1[n] \otimes x_2[n]) \otimes x_3[n] = x_1[n] \otimes (x_2[n]) \otimes x_3[n]$ |
|               distributive               | $x_1[n] \otimes (x_2[n] + x_3[n]) = x_1[n] \otimes x_2[n] + x_1[n] \otimes x_3[n]$ |



#### 2.2.3 Sampling Rate Alteration

If $x[n]$, a sequence with a sampling rate of $F_T$ Hz, is used to generate another sequence $y[n]$ with a desired sampling rate of $F_T'$, then the *sampling rate alternative ratio* is given by
$$
\frac{F_T'}{F_T} = R
$$

- Up-sampling

    $L-1$ equidistant zero-valued samples are inserted between each two consecutive samples of $x[n]$.

$$
x_u[n] = \left\{
\begin{array}{cl}
x[n/L], & n=0, \pm L, \pm 2L, \dots \\
0, & \text{otherwise}
\end{array}
\right.
$$

​		The sampling rate of $x_u[n]$ is $L$ times larger than that of $x[n]$.

- Down-sampling

    Keep every $L$th sample of $x[n]$ and removing $L-1$ between samples.

$$
y[n] = \left\{
\begin{array}{cl}
x[nL], & n=0, \pm L, \pm 2L, \dots \\
0, & \text{otherwise}
\end{array}
\right.
$$

​		The sampling rate of $y[n]$ is $(1/L)$-th that of $x[n]$.



#### 2.2.4 Classification of Sequences

##### 1 - Classification Based on Symmetry

- Real-value Sequence

    - Even

        If $x[n]$ is known, $0 \leq n \leq N_1$, create an even sequence based on $x[n]$
        $$
        x'[n] = x[n] + x[-n]
        $$

    - Odd

        Conversely, create an odd sequence based on $x[n]$
        $$
        x'[n] = x[n] - x[-n]
        $$

    - Non-symmetry (General)
        $$
        x[n] = x_{\text{ev}}[n] + x_{\text{odd}}[n]
        $$
        $x_{\text{ev}}[n], x_{\text{odd}}[n]$ are called, respectively, the even part and odd part.
        $$
        x_{\text{ev}}[n] = \frac{1}{2}(x[n] + x[-n]) \\
        x_{\text{odd}}[n] = \frac{1}{2}(x[n] - x[-n])
        $$

- Complex-value Sequence

    - Conjugate-symmetric
        $$
        x[n] = x^* [-n]
        $$
        The real part is even symmetric while the imaginary part is odd symmetric.

    - Conjugate-antisymmetric
        $$
        x[n] = -x^*[-n]
        $$
        The real part is odd symmetric while the imaginary part is even symmetric.

    - Non-symmetry (general sequence) complex value
        $$
        x[n] = x_{\text{cs}}[n] + x_{\text{ca}}[n]
        $$
        $x_{\text{cs}}[n], x_{\text{ca}}[n]$ are the conjugate-symmetric and conjugate-antisymmetric part respectively.
        $$
        x_{\text{cs}}[n] = \frac{1}{2}(x[n] + x^*[-n]) \\
        x_{\text{ca}}[n] = \frac{1}{2}(x[n] - x^*[-n])
        $$

##### 2 - Periodic and Aperiodic Signals

A periodic sequence $\tilde x[n]$ with a *period* $N$ satisfying
$$
\tilde x[n] = \tilde x[n+kN]~~~~~~~\text{for all } n
$$
where the *fundermatal period* $N_f$ is the smallest value of $N$.

The period of the sum of two periodic sequence is given by
$$
N = \text{LCM}(N_a,N_b)= \frac{N_aN_b}{GCD(N_a,N_b)}
$$
where LCM denoted the least common multiple.

##### 3 - Energy and Power Signals

The total *energy* of a sequence $x[n]$ is defined by
$$
\mathscr E_x = \sum\limits_{n=-\infin}^\infin |x[n]|^2
$$
Define energy over a finite interval $-K ≤ n ≤ K$ as
$$
\mathscr E_{x,K} = \sum\limits_{n=-K}^K |x[n]|^2
$$
then the *average power* is given by
$$
\mathscr P_x = \lim_{K \to \infin}\frac{1}{2K+1}\mathscr E_{x,K}
$$
Specially, for a periodic signal, its average power is difined by
$$
\mathscr P_x = \frac{1}{N}\sum\limits_{n=0}^{N-1} |\tilde x[n]|^2
$$
It can be seen that if the energy $\mathscr E_x$ is finite, then its average power $\mathscr P_x$ is zero.

- Energy Signal

    A finite energy signal with zero average power, which is root-mean-squared bounded.
    $$
    \|x\|_2 = \left(\sum\limits_{-\infin}^\infin |x[n]|^2\right)^{1/2} ≤ B_x
    $$
    ex.  a finite-length sequence

- Power Signal

    An infinite energy signal with finite average power.
    $$
    \mathscr P_x = \lim_{K \to \infin}\frac{1}{2K+1}\mathscr E_{x,K} ≤ B_x
    $$
    ex.  a periodic signal

##### 4 - Bounded and Non-bounded Signals

- Magnitude Bounded (peak absolute value bounded)

    $$
    \|x\|_\infin = |x[n]|_{max} \leq B_x < \infin
    $$

- Summable Sequence (mean absolute value bounded)

    $$
    \|x\|_1 = \sum\limits_{n = -\infin}^\infin|x[n]| ≤ B_x < \infin
    $$



### 2.3 Some Basic Digital Signals (Sequence)

- Unit Sample Sequence
    $$
    \delta[n]=
    \left\{
    \begin{array}{lr}
    1, & n=0 \\
    0, & n\neq 0
    \end{array}\right. \nonumber
    $$
    The unit sample sequence shifted by $k$ samples (ex. delay $k$ samples)
    $$
    \delta[n-k]=
    \left\{
    \begin{array}{lr}
    1, & n=k \\
    0, & n\neq k
    \end{array}\right. \nonumber
    $$
    An arbitrary sequence can be represented in the time domain as a weighted sum of the delayed and advanced versions of a basic sequence.

    ex.  $x[n]=\{10, -7, 10, 9, 11\},~-2\leq n \leq 2$
    $$
    \begin{align}
    x[n] &= \sum\limits_{k=-2}^{2}\delta[n-k]x[k] \nonumber \\
    &= 10\delta[n+2] -7\delta[n+1] + 10\delta[n] + 9\delta[n-1] + 11\delta[n-2] \nonumber
    \end{align}
    $$

- Unit Step Sequence
    $$
    \mu[n]=
    \left\{
    \begin{array}{lr}
    1, & n\geq0 \\
    0, & n < 0
    \end{array}\right. \nonumber
    $$
    The unit step sequence shifted by $k$ samples (ex. delay $k$ samples)
    $$
    \mu[n-k]=
    \left\{
    \begin{array}{lr}
    1, & n\geq k \\
    0, & n < k
    \end{array}\right. \nonumber
    $$
    the relation between $\delta[n]$ and $\mu[n]$
    $$
    \begin{align}
    \mu[n] &= \sum\limits_{m=0}^\infin \delta[n-m]=\sum\limits_{k=-\infin}^n \delta[k] \\
    \delta[n] &= \mu[n] - \mu[n-1]
    \end{align}
    $$

- Exponential Sequence

    Decay & Growing : $x[n]=\alpha^n$

    Euler's formula is the fundamental of fourier transform.
    $$
    e^{j\theta} = \cos\theta + j\sin\theta
    $$

- Sinusoidal digital
    $$
    A\sin(\Omega t + \phi) ~\xRightarrow[\text{t=nT}]{\text{sampling}}~ A\sin(\omega_0 n+\phi)
    $$
    $A$ ---- amplitude    $\phi$ ---- phase    $T$ ---- sampling 

    $\Omega$, $rad/s$  ---- angular frequency    $\omega_0$, $rad$ ---- normalized angular frequency
    $$
    \omega_0 = \Omega T
    $$
    Suppose that sampled signal is periodic, denote $N$ as period of sinusoidal frequency,
    $$
    \omega_0(n + N) = \omega_0 n + 2k\pi ~~\Rightarrow ~~\omega_0 N = 2k\pi ~~\Rightarrow~~ N=\frac{2k\pi}{\omega_0}
    $$
    which turns out that $\omega_0$ should be the form of $k_0\pi,~k_0 \in Z^*$.

    In this situation, normally, $-\pi \leq \omega_0 \leq \pi$.

    - $w_0 = 2k\pi$ is low frequency for sinusoidal sequence

    - $w_0 = (2k+1)\pi$ is high frequency for sinusoidal sequence



## 3. Discrete-Time Systems

### 3.1 Discrete-Time System Examples



#### 3.1.1 Accumulator

$$
y[n] = \sum\limits_{l=-\infin}^n x[l]
$$

The out put $y[n]$  at time instant $n$ is the sum of the input sample value $x[n]$ at time instant $n$ and all past inputs samples.

The above equation can also be written in the recursive form
$$
y[n] = y[n-1] + x[n]
$$
Another variation of the accumulator is given by
$$
y[n] = y[-1] + \sum\limits_{l=0}^n x[l],~~~~~n≥0
$$
which is used for a casual input sequence where $y[-1]$ is called the *initial condition*.



#### 3.1.2 Moving-Average Filter

In applications where data measurements cannot be repeated, a kind of methods to reduce noises is to average $M$ samples of $x[l]$ available for $n-M+1 ≤ l ≤ n$, which is called *M-point average*.
$$
y[n] = \frac{1}{M}\sum\limits_{l=0}^{M-1} x[n-l]
$$
The whole system is called *M-point moving-average filter*.

A more efficient implementation using recursive equation is given by
$$
y[n] = y[n-1] + \frac{1}{M}(x[n]-x[n-M])
$$


### 3.2 Classification of Discrete-Time Systems



#### 3.2.1 Linear System

if $y_1[n]$ and $y_2[n]$ are the responses to the input $x_1[n]$ and $x_2[n]$, respectively, then for an input
$$
x[n] = \alpha x_1[n] + \beta x_2[n]
$$
the response is given by
$$
y[n] = \alpha y_1[n] + \beta y_2[n]
$$
which can be represented as
$$
T(\alpha x_1[n] + \beta x_2[n]) = \alpha T(x_1[n]) + \beta T(x_2[n])
$$
It turns out that, in a linear system, a complicated sequence can be decomposed as a weighted combination of some simple sequences.



#### 3.2.2 Shift-Invariant System

A system is shift-invariant (aka time-invariant) if and only if, for any input $x_1[n]$, shifting the input by some number of samples $n_0$, and then passing it through the system, gives exactly the same result as passing it through the system, and then shifting it.
$$
T(x[n-n_0]) = y[n-n_0]
$$
ex. up-sampler is time-variant

​	For an input $x_1[n] = x[n-n_0]$, the output is
$$
x_{1,u}[n] = \left\{
\begin{array}{cl}
x_1[n/L] & n=0, \pm L, \pm 2L, \dots \\
0 & \text{otherwise}
\end{array}
\right.
$$
​	Then replace $n$ with $n/L$ in $x_1[n] = x[n-n_0]$, we get
$$
x_1[n/L] = x[n/L - n_0]
$$
​	which generate the new equation that
$$
x_{1,u}[n] = \left\{
\begin{array}{cl}
x[n/L - n_0] & n=0, \pm L, \pm 2L, \dots \\
0 & \text{otherwise}
\end{array}
\right.
$$
​	However, shift $x_u[n]$ by $n_0$
$$
x_u[n-n_0] =
\left\{
\begin{array}{cl}
x[(n-n_0)/L] & n=0, \pm L, \pm 2L, \dots \\
0 & \text{otherwise}
\end{array}
\right.
\neq x_{1,u}[n]
$$


#### 3.2.3 Causal System

A *causal system* is a system whose response does not depend on the future inputs and it relies only on the past and present inputs, which means the future samples are zero-valued, that is
$$
x[n-k]=0, k<0 \\ y[n-k] = 0, 𝑘<0
$$
It can be demonstrated that the impulse response of the sysmtem is a causal sequence, that is
$$
h[n] = 0,~n<0
$$
which will be proved later.

A system that depends solely on future input values is an *anti-causal system*, which conversely means
$$
x[n-k]=0, k>0 \\ y[n-k] = 0, 𝑘>0
$$
Systems other than those mentioned above are *non-causal system*, which means
$$
x[n-k] \neq 0, k<0 ~~~~\text{or}~~~~ y[n-k] \neq 0, 𝑘<0
$$


#### 3.2.4 Stable System

If and only if for every bounded input, the output is also bounded, which implies that
$$
|x[n]| < B_x
$$
for all values of $n$, then
$$
|y[n]| < B_y
$$
This type of stability is referred to as *bounded-input, bounded-output* (BIBO) *stability*.



#### 3.2.5 Passive and Lossless Systems

In *passive system*, for every finite input sequence $x[n]$, the output sequence $y[n]$ has, at most, the same energy, that is
$$
\sum\limits_{n=-\infin}^\infin |y[n]|^2
≤
\sum\limits_{n=-\infin}^\infin |x[n]|^2
< \infin
$$
If the above inequality is satisfied with an equal sign for all inputs, such system is called *lossless system*.
$$
\sum\limits_{n=-\infin}^\infin |y[n]|^2
=
\sum\limits_{n=-\infin}^\infin |x[n]|^2
< \infin
$$


### 3.3 Impulse and Step Responses

The response of a digital filter to a unit sample sequence $\{\delta [n]\}$ is called the *unit sample response*, or simply, the *impulse response*, and id denoted as $\{h[n]\}$.
$$
x[n] = \delta [n]
$$
Correspondingly, the response of discrete-time system to a unit step sequence $\{\mu[n]\}$, denoted as $\{s[n]\}$, is its *unit step response*, or simply, *step response*.
$$
x[n] = \mu[n]
$$
if $h[n]$ is finite-length, the system is called *finite impulse response* (FIR), which can be calculated directly with convolution.

If $h[n]$ is infinite-length, the system is called *infinite impulse response* (FIR), which can be converted to real-time recursive computation, but could not be calculated directly with convolution.



### 3.4 Time-Domain Characterization of LTI Discrete-Time Systems

A *linear time-invariant* (LTI) discrete-time system satisfies both the linearity and the time-invariance properties.



#### 3.4.1 Input-Output Relationship

LTI discrete-time system is completely characterized by its impulse response, that is, the output can be calculated directly with convolution.

$x[n]$ can be expressed as a weighted linear combination,
$$
x[n] = \sum\limits_{k=-\infin}^\infin x[k]\delta[n-k]
$$
and since such system is tiem-invariant, its response to $\delta[n-k]$ is $h[n-k]$, then $y[n]$ is given by
$$
y[n] = \sum\limits_{k=-\infin}^\infin x[k]h[n-k]
$$
which can be alternatively written as
$$
y[n] = \sum\limits_{k=-\infin}^\infin x[n-k]h[k]
$$


#### 3.4.2 The Performance of LTI

- Stability

    An LTI discrete-time system is BIBO stable if and only if its impulse response $h[n]$ is absolutely summable,
    $$
    i.e.~~ \sum\limits_{-\infin}^\infin |h[n]| < \infin
    $$

- Causality

    An LTI discrete-time system is causal if and only if its impulse $h[n]$ is a causal sequence.

    Recall the determination of causality, $h[n] = 0,~n<0$, we now give the proofs.

    *proof :*

    Take $y[n] = \sum\limits_{k=-\infin}^\infin x[k]h[n-k]$ for an example, we replace the time variable $t$ by a fixed value $t_0$,
    $$
    y[n_0] = \sum\limits_{k=-\infin}^\infin x[k]h[n_0-k]
    $$
    As such input depending only on values of $k ≤ n_0$, we must have its contribution to the integral being nulled out by requiring the value of the impulse response
    $$
    h[n_0−k]=0 ~~~\text{for}~~~ k>n_0
    $$
    By making a change of variables $n=n_0−k$ (so that $k=n_0−n$), this means that
    $$
    h[n] = 0~~~~\text{for}~~~~n<0
    $$



