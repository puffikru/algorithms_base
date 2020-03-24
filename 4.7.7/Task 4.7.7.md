$\displaystyle \frac{\displaystyle \sum_{j = 1}^k v_{i_j}}{\displaystyle \sum_{j = 1}^k w_{i_j}} \quad = \quad \frac{v_{i_1} + v_{i_2} … v_{i_k}}{w_{i_1} + w_{i_2} … w_{i_k}}$

$\displaystyle\frac{1 + 1}{1 + 2} = \frac{2}{3} = 2 / 3 = 0.66666$


**Примеры**:

Если $k = 3$, то $(v_1 + v_2 + v_3) / (w_1 + w_2 + w_3) = a$

$(v_1 + v_2 + v_3) / (w_1 + w_2 + w_3) - a = 0$

$(v_1 + v_2 + v_3) - a \cdot (w_1 + w_2 + w_3) = 0$

$(v_1 - a \cdot w_1) + (v_2 - a \cdot w_2) + (v_3 - a \cdot w_3) = 0$



$\displaystyle \sum_{j = 1}^k v_{i_j}  \leq 10^7 =>$ при максимальном размере  $v = 10^6, k = 10$

$\displaystyle \sum_{j = 1}^k w_{i_j} \leq 10^7  =>$ при максимальном размере  $w = 10^6, k = 10$

$1 \leq k \leq n \leq 1000$

$\displaystyle \frac{0}{1} \to \frac{10^7}{10^7}$

```
3 2
1 1
1 2
1 3

0.66667
```

$(1 + 1) / (1 + 2) = 0.66666$


**Проверка**: Если при таком $a$ это выражение - 

$(v_1 + v_2 + v_3) - a \cdot (w_1 + w_2 + w_3) \ge 0$ возвращаем `true`


