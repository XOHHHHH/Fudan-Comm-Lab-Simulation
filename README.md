# Fudan-Comm-Lab-Simulation

[![MATLAB](https://img.shields.io/badge/MATLAB-Simulation-blue.svg)]()

### 🇨🇳 项目简介
本项目是复旦大学通信系统大作业的核心成果。我们搭建了一套完整的 MATLAB 仿真系统，模拟图像数据在带噪信道中的传输过程。该项目深入对比了不同信源与信道编码方案的级联性能，特别是揭示了变长编码（Variable-Length Coding）在信道误码下的失步扩散规律，以及维特比软判决（Soft-Decision Viterbi）带来的 2dB 编码增益。

### 🇬🇧 Project Overview
This project is a core achievement of the Communication Systems coursework at Fudan University. We built a full-chain MATLAB simulation system to model image data transmission over AWGN channels. This repository explores the cascaded performance of various source coding (Huffman/Fano/Shannon) and channel coding (Hamming/Convolutional) schemes, with a deep focus on error propagation mechanisms and the 2dB coding gain achieved by soft-decision Viterbi decoding.

---

### 核心亮点 (Key Highlights)
* **编码架构 (Coding Architecture)：** 实现了信源（哈夫曼/费诺/香农）与信道（汉明/卷积）编码的级联架构。
* **算法调优 (Algorithmic Insight)：** 通过对比软/硬判决机制，成功量化了软判决在物理层带来的 2dB 增益。
* **科学分析 (Scientific Analysis)：** 对“变长码失步”和“BER 瀑布门槛效应”进行了严谨的数学推导与实验验证。

### 目录结构 (Directory Structure)
```text
/src              # 核心代码模块
├── /source       # 信源编码 (Huffman, Fano, Shannon)
├── /channel      # 信道编码 (Hamming, Convolutional)
└── main.m        # 仿真主控程序
/docs             # 设计报告与流程图
