# 第二章 Fast Fourier Transform

### DFT 问题定义

给定一组 $n$ 个复数 $x(j), 0 \le j \lt n$, 定义其离散傅里叶变换输出新的一组 $n$ 个复数 $y(k),0 \le k \lt n$。满足 
$$y(k) = \sum^{n-1}_{j=0} x(j) \omega_{n}^{jk}$$
其中 $\omega_n = e^{-2 \pi i / n}$ , 可以证明
$$x(j) = \frac{1}{n} \sum^{n-1}_{k=0} y(k) \omega_{n}^{-jk}$$

### FFT 问题定义
直接使用定义公式计算 DFT 的复杂度为 $O(n^2)$, FFT 寻求复杂度为 $O(n\log\ n)$ 的 DFT 算法

### 对半分治的思想
假设 $n$ 是偶数，则 DFT 公式可写成
$$y(k) = \sum^{n/2-1}_{j=0} x(j) \omega_{n}^{jk} + x(j + n/2) \omega_{n}^{(j+n/2)k} =\sum^{n/2-1}_{j=0} [x(j) + x(j+n/2)\omega_n^{nk/2}] \omega_n^{jk}$$

$$y(2k) =\sum^{n/2-1}_{j=0} [x(j) + x(j+n/2)] \omega_{n/2}^{jk}$$

$$y(2k+1) =\sum^{n/2-1}_{j=0} [x(j) -x(j+n/2)] \omega_{n}^{j}\omega_{n/2}^{jk}$$
这样的递归计算，可以把 DFT 的复杂度降低到 $O(n\log n)$，即得到 FFT