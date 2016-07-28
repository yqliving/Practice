class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        auto r = 0;
        for (auto i = 0; i < 32; ++i) {
            r = (r << 1) | ((n >> i) & 1);   //r每次左移一个，((n >> i) & 1)每次取出一位的值
        }
        return r;
    }
};
