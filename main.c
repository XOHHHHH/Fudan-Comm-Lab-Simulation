% =========================================================================
% Fudan-Comm-Lab-Simulation: 图像鲁棒传输系统仿真主控程序
% 作者: 熊简
% 功能: 实现图像传输的全链路仿真，包含信源编码、信道编码、AWGN信道与译码
% =========================================================================
clc; clear; close all;

%% 1. 系统参数配置 (控制变量区域)
% -------------------------------------------------------------------------
% 信源编码配置
source_coding_enable = true;      % 是否启用信源编码
source_method = 'Huffman';        % 可选: 'Huffman', 'Fano', 'Shannon'
huffman_block = 1;                % 哈夫曼分组长度 (1, 2, 或 4)

% 信道编码配置
channel_coding_enable = true;     % 是否启用信道编码
channel_method = 'Convolutional'; % 可选: 'Hamming', 'Convolutional'
use_soft_decision = true;         % 卷积码是否开启软判决 (2dB增益核心)

% 仿真范围
SNR_range = 0:2:12;               % 信噪比遍历范围 (dB)
fprintf('系统已配置: 信源[%s], 信道[%s], 软判决[%d]\n', ...
        source_method, channel_method, use_soft_decision);

%% 2. 仿真核心循环
% -------------------------------------------------------------------------
BER_results = zeros(size(SNR_range));

for i = 1:length(SNR_range)
    current_SNR = SNR_range(i);
    
    % Step 1: 原始图像数据准备
    % [此处调用你的图像读取与数据预处理模块]
    % img_bits = load_image_bits('test.jpg'); 
    
    % Step 2: 信源编码 (根据配置动态路由)
    if source_coding_enable
        % [此处接入你编写的 source_encode.m]
        % encoded_bits = source_encode(img_bits, source_method, huffman_block);
    end
    
    % Step 3: 信道编码 (根据配置动态路由)
    if channel_coding_enable
        % [此处接入你编写的 channel_encode.m]
        % ch_bits = channel_encode(encoded_bits, channel_method);
    end
    
    % Step 4: 调制与信道传输 (AWGN)
    % [此处模拟 BPSK 调制并叠加高斯噪声]
    % received_signal = awgn(mod_bits, current_SNR);
    
    % Step 5: 解调与译码
    % if channel_coding_enable
    %     decoded_bits = channel_decode(received_signal, channel_method, use_soft_decision);
    % end
    
    % Step 6: 误码率统计 (BER Calculation)
    % BER_results(i) = sum(abs(original_bits - decoded_bits)) / length(original_bits);
    
    fprintf('当前 SNR = %.2f dB 时，BER = %.6f\n', current_SNR, BER_results(i));
end

%% 3. 结果可视化
% -------------------------------------------------------------------------
figure('Color', 'w');
semilogy(SNR_range, BER_results, '-o', 'LineWidth', 2, 'MarkerSize', 8);
grid on;
xlabel('信噪比 SNR (dB)');
ylabel('误码率 BER');
title(['级联系统性能曲线: ' source_method ' + ' channel_method]);
legend(['软判决 = ' num2str(use_soft_decision)]);

fprintf('✅ 仿真流程结束。曲线图已生成，建议存为 .fig 文件备用。\n');
