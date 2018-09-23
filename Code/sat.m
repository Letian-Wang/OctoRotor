function y =sat(x,a)
%UNTITLED2 此处显示有关此函数的摘要
%   此处显示详细说明

if x>a
    jieguo=a;
else if x<-a
        jieguo=-a;
else
    jieguo=x;
    end
end

y=jieguo;       
end

