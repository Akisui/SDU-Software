## Chapter 3

<h5 align="right">张志恒 202100202072 地空1班</h5>

#### Excercise 9.

1. $\boldsymbol{5n^2 - 6n = \Theta (n^2)}$

    $(n \geq 1)~~5n^2 - 6n < 5n^2 ~~\Rightarrow~~ f(n) = O(n^2)$.

    $(n \geq 6)~~5n^2 - 6n \geq 5n^2 - n^2 = 4n^2 ~~\Rightarrow~~ f(n) = \Omega(n^2)$.

    $\bold{i.e.}~~5n^2 - 6n = \Theta(n^2)$

    

2. $\boldsymbol {n! = O(n^n)}$

    $(\text{for} ~i = 1 ~ \text to ~ n )~~ i \leq n ~~\Rightarrow ~~\prod\limits_{i = 1}^n i \leq n^n$.

    $\bold{i.e.}~~n! = O(n^n)$

    

3. $\boldsymbol{2n^2 2^n + n\log n = \Theta(n^2 2^n)}$

    $(n \geq 1)~~2n^2 2^n + n\log n \leq 2n^2 2^n + n^2 \leq 3n^2 2^n ~~\Rightarrow~~ f(n) = O(n^22^n)$.

    $(n \geq 1)~~2n^2 2^n + n\log n > 2n^2 2^n ~~\Rightarrow~~ f(n) = \Omega(n^22^n)$.

    $\bold{i.e.}~~2n^2 2^n + n\log n = \Theta(n^22^n)$

    

4. $\boldsymbol{\sum\limits_{i=0}^n i^2 = \Theta(n^3)}$

    $(n \geq 4)~~\sum\limits_{i=0}^n i^2= \cfrac{n(n+1)(2n+1)}{6} \leq \cfrac{4}{3}(n + 1)^3  = \cfrac{4}{3} (n^3 + 3n^2 + 3n + 1) \leq  2n^3 + n^2 \leq 3n^3$

    ​		    	$\Rightarrow~~ f(n) = O(n^3)$

    $(n \geq 1)~~\sum\limits_{i=0}^n i^2= \cfrac{n(n+1)(2n+1)}{6} > \cfrac{1}{3}n^3 ~~\Rightarrow~~ f(n) = \Omega(n^3)$

    $\bold{i.e.}~~\sum\limits_{i=0}^n i^2 = \Theta(n^3)$

    

5. $\boldsymbol{\sum\limits_{i=0}^n i^3 = \Theta(n^4)}$

    $(n \geq 4)~~\sum\limits_{i=0}^n i^3 = \cfrac{n^2(n+1)^2}{4} \leq \cfrac{1}{4} (n + 1)^4 \leq \cfrac{3}{4} n^3 \cdot 2n \leq \cfrac{3}{2}n^4 ~~\Rightarrow~~ f(n) = O(n^4)$

    $(n \geq 1)~~\sum\limits_{i=0}^n i^3= \cfrac{n^2(n+1)^2}{4} > \cfrac{1}{4}n^4 ~~\Rightarrow~~ f(n) = \Omega(n^4)$

    $\bold{i.e.}~~\sum\limits_{i=0}^n i^3 = \Theta(n^4)$

    

6. $\boldsymbol{n^{2^n} + 6 \cdot 2^n = \Theta(n^{2^n})} $

    $(n > 1)~~n^{2^n} + 6 \cdot 2^n < n^{2^n} + 6 \cdot n^{2^n} = 7 n^{2^n} ~~\Rightarrow~~ f(n) = O(n^{2^n}) $

    $(n \geq 1) n^{2^n} + 6 \cdot 2^n > n^{2^n} ~~\Rightarrow~~ f(n) = \Omega(n^{2^n})$

    $\bold{i.e.}~~n^{2^n} + 6 \cdot 2^n = \Theta(n^{2^n})$

    

7. $\boldsymbol{n^3 + 10^6n^2 = \Theta(n^3)}$

    $(n \geq {10}^6)~~n^3 + 10^6n^2 \leq n^3 + n^3 = 2n^3 ~~\Rightarrow~~ f(n) = O(n^3)$

    $(n \geq 1)~~ n^3 + 10^6n^2 > n^3 ~~\Rightarrow~~ f(n) = \Omega(n^3)$

    $\bold{i.e.}~~n^3 + 10^6n^2 = \Theta(n^3)$

    

8. $\boldsymbol{\cfrac{6n^3}{\log n + 1} = O(n^3)}$

    $(n \geq 1)~~ \cfrac{6n^3}{\log n + 1} \leq 6n^3$

    $\bold{i.e.}~~ \cfrac{6n^3}{\log n + 1} = O(n^3)$

    

9. $\boldsymbol{n^{1.001} + n \log n = \Theta(n ^{1.001})}$

    $(n \geq 3)~~ n^{1.001} + n \log n < 2n^{1.001} ~~\Rightarrow~~ f(n) = O(n^{1.001})$

    $(n \geq 1)~~n^{1.001} + n \log n > n^{1.001} ~~\Rightarrow~~ f(n)=\Omega(n^{1.001})$

    $\bold{i.e.}~~n^{1.001} + n \log n = \Theta(n^{1.001})$

    

10. $\boldsymbol{n^{k + \epsilon} + n^k \log n = \Theta(n^{k + \epsilon}),~k \geq 0 ~\bold{ and }~ \epsilon > 0}$

    $(n > \epsilon^{-\epsilon})~~\log n < n^\epsilon ~\to~ n^{k + \epsilon} + n^k \log n < 2 n^{k + \epsilon} ~~\Rightarrow~~ f(n) = O(n^{k + \epsilon})$

    $(n \geq 1)~~n^{k + \epsilon} + n^k \log n > n^{k + \epsilon} ~~\Rightarrow~~ f(n) = \Omega(n^{k + \epsilon})$

    $\bold{i.e.}~~n^{k + \epsilon} + n^k \log n = \Theta(n^{k + \epsilon})$