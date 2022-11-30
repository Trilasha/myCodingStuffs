class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> v(2);
        double f=celsius+273.15;
        double k=celsius*1.80 + 32.00;
        
        v[0]=f;
        v[1]=k;
        
        return v;
        
    }
};