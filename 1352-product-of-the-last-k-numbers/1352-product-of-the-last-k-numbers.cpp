class ProductOfNumbers {
public:
    vector<int> v;

    ProductOfNumbers() {
        v.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            v.clear();
            v.push_back(1);
        } else {
            v.push_back(v.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= v.size())
            return 0;

        return v.back() / v[v.size() - k - 1];
    }
};