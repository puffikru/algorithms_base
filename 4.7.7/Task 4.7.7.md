
$\displaystyle \frac{\displaystyle \sum_{j = 1}^k v_{i_j}}{\displaystyle \sum_{j = 1}^k w_{i_j}} \quad = \quad \frac{v_{i_1} + v_{i_2} … v_{i_k}}{w_{i_1} + w_{i_2} … w_{i_k}}$



**Input**:

```
4 3
10 1
10 1
9000 1000
8 1
```
**Output**:

```
9.33333
```

$\displaystyle \frac{10^7}{1}$

$0.55555$

В математике `биномиальные коэффициенты` — это коэффициенты в разложении  $(1+x)^n$ по степеням `x`. Коэффициент при $x^k$ обозначается $\textstyle\binom{n}{k}$ или $\textstyle C_n^k$ и читается «биномиальный коэффициент из `n` по `k`» (или «число сочетаний из `n` по `k`», $\textstyle C_n^k$ читается как «це из `n` по `k`»):
{{EF|:|$(1+x)^n=\binom{n}{0}+\binom{n}{1}x+\binom{n}{2}x^2+\ldots+\binom{n}{n}x^n =\sum_{k=0}^{n} \binom{n}{k} x^k,$|ref=1}}
для [[натуральное число|натуральных]] степеней $n$ 

$$\frac{\sum v_i}{\sum w_i} - \frac{\sum v_j}{\sum w_j} > 0$$

$$
V_{big} := \sum v_i := V + v_a\
W_{big} := \sum w_i := W + w_a\
$$
$$
V_{small} := \sum v_j := V + v_b\
W_{small} := \sum w_j := W + w_b\
$$

$$\frac{\sum v_i}{\sum w_i} - \frac{\sum v_j}{\sum w_j} > 0$$  multiply by $${\sum w_i} \cdot {\sum w_j}$$

$$\sum v_i \cdot \sum w_j - \sum v_j \cdot \sum w_i > 0$$

$$(V+v_i)(W+w_j) - (V + v_j)(W + w_i) > 0$$

$$V W + V w_j + v_i W + v_i w_j - V W - V w_i - v_j W - v_j w_i > 0$$

$$V(w_j - w_i) + W(v_i - v_j) + v_i w_j - v_j w_i > 0$$

$$v_i w_j = v_i (w_j - w_i + w_i) = v_i (w_j - w_i) + v_i w_i$$

$$V(w_j - w_i) + W(v_i - v_j) + v_i (w_j - w_i) + v_i w_i - v_j w_i > 0$$

$$(w_j - w_i)(V + v_i) + W(v_i - v_j) + w_i(v_i - v_j) > 0$$

$$(w_j - w_i)(V + v_i) + (v_i - v_j)(W + w_i) > 0$$

$$(w_j - w_i)V_{big} + (v_i - v_j)W_{big} > 0$$


$$
\sin(a + b ) = \sin(a)\cos(b) + \cos(a)\sin(b)
$$



Depending on the value of $x$ the equation `\( f(x) = \sum_{i=0}^{n} \frac{a_i}{1+x} \)` may diverge or converge.

$$ f(x) = \sum_{i=0}^{n} \frac{a_i}{1+x} $$

In-line maths elements can be set with a different style: `\(f(x) = \displaystyle \frac{1}{1+x}\)`. The same is true the other way around:

$$\displaystyle C_n^k$$
$$\textstyle\binom{n}{k}$$