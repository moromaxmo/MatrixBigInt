/*
 * Name: Omar Ahmed Amer Abdulrahim
 * Email: itsomarahmed@gmail.com
 * Phone_num: 01002787452
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class BigInteger {
private:
    string num;
public:

    BigInteger(string n) {
        num = n;
        clear();
        trunc();
    }

    BigInteger(short n) {
        num = to_string(n);
        clear();
        trunc();
    }

    BigInteger(int n) {
        num = to_string(n);
        clear();
        trunc();
    }

    BigInteger(unsigned int n) {
        num = to_string(n);
        clear();
        trunc();
    }

    BigInteger(long n) {
        num = to_string(n);
        clear();
        trunc();
    }

    BigInteger(unsigned long n) {
        num = to_string(n);
        clear();
        trunc();
    }

    BigInteger(long long n) {
        num = to_string(n);
        clear();
        trunc();
    }

    BigInteger(unsigned long long n) {
        num = to_string(n);
        clear();
        trunc();
    }

    BigInteger() {
        num = "";
    }

    void trunc() {
        bool flag = false;
        if (num[0] == '-') {
            num.erase(num.begin());
            flag = true;
        }
        for (int i = 0; i < num.length(); i++) {
            if (num[i] < '0' || num[i] > '9') {
                cout << "!MISMATCH ERROR\\ INVALID INPUT TYPE TOKIN: '" << num[i] << "', THE NUMBER WILL BE TRUNCATED.\n"
                        "ALLOWED INPUTS ARE NUMBERS 0-9 ONLY!\n";
                num.erase(num.begin() + i, num.end());
                break;
            }
        }
        if (flag) {
            reverse(num.begin(), num.end());
            num.push_back('-');
            reverse(num.begin(), num.end());
        }
    }

    void clear() {
        bool flag = false;
        if (num[0] == '-') {
            num.erase(num.begin());
            flag = true;
        }
        while (this->num[0] == '0' && num.length() > 1)
            num.erase(this->num.begin());
        if (flag) {
            reverse(num.begin(), num.end());
            num.push_back('-');
            reverse(num.begin(), num.end());
        }
    }

    bool operator<(const BigInteger& rhs) const {
        int n1 = num.length(), n2 = rhs.num.length();
        if (num[0] == '-' && rhs.num[0] != '-')
            return true;
        if (num[0] != '-' && rhs.num[0] == '-')
            return false;
        //if both are +ve
        if (num[0] != '-' && rhs.num[0] != '-') {
            if (n1 < n2) {
                return true;
            }
            if (n1 > n2 || num == rhs.num) {
                return false;
            }
            for (int i = 0; i < n1; i++) {
                if (num[i] < rhs.num[i]) {
                    return true;
                } else if (num[i] > rhs.num[i]) {
                    return false;
                }
            }
            return false;
        }
        //if both are -ve
        if (num[0] == '-' && rhs.num[0] == '-') {
            if (n1 < n2) {
                return false;
            }
            if (n1 > n2 || num == rhs.num) {
                return true;
            }
            for (int i = 0; i < n1; i++) {
                if (num[i] < rhs.num[i]) {
                    return false;
                } else if (num[i] > rhs.num[i]) {
                    return true;
                }
            }
            return true;
        }
        cout << "Invalid comparison!\n";
        return false;
    }

    bool operator>(const BigInteger& rhs) const {
        return rhs < (*this);
    }

    bool operator==(const BigInteger& rhs) const {
        return !((*this) < rhs || rhs < (*this));
    }

    bool operator<=(const BigInteger& rhs) const {
        return (*this) < rhs || (*this) == rhs;
    }

    bool operator>=(const BigInteger& rhs) const {
        return rhs <= (*this);
    }

    bool operator!=(const BigInteger&rhs) const {
        return !((*this) == rhs);
    }

    BigInteger operator=(BigInteger rhs) {
        this->num = rhs.num;
        return *this;
    }

    BigInteger operator=(short n) {
        string s = to_string(n);
        BigInteger rhs(s);
        this->num = rhs.num;
        return *this;
    }

    BigInteger operator=(int n) {
        string s = to_string(n);
        BigInteger rhs(s);
        this->num = rhs.num;
        return *this;
    }

    BigInteger operator=(unsigned int n) {
        string s = to_string(n);
        BigInteger rhs(s);
        this->num = rhs.num;
        return *this;
    }

    BigInteger operator=(long n) {
        string s = to_string(n);
        BigInteger rhs(s);
        this->num = rhs.num;
        return *this;
    }

    BigInteger operator=(unsigned long n) {
        string s = to_string(n);
        BigInteger rhs(s);
        this->num = rhs.num;
        return *this;
    }

    BigInteger operator=(long long n) {
        string s = to_string(n);
        BigInteger rhs(s);
        this->num = rhs.num;
        return *this;
    }

    BigInteger operator=(unsigned long long n) {
        string s = to_string(n);
        BigInteger rhs(s);
        this->num = rhs.num;
        return *this;
    }

    BigInteger operator+(BigInteger& rhs) {
        if (num[0] == '-') {
            BigInteger temp(num);
            temp.num.erase(temp.num.begin());
            return (rhs - temp);
        }
        if (rhs.num[0] == '-') {
            BigInteger temp(rhs.num);
            temp.num.erase(temp.num.begin());
            return ((*this) - temp);
        }
        BigInteger res;
        bool flag = false;
        if (num.length() > rhs.num.length()) {
            swap(num, rhs.num);
            flag = true;
        }
        int n1 = num.length(), n2 = rhs.num.length();
        reverse(num.begin(), num.end());
        reverse(rhs.num.begin(), rhs.num.end());
        int carry = 0;
        for (int i = 0; i < n1; i++) {
            int sum = ((num[i] - '0') + (rhs.num[i] - '0') + carry);
            res.num.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        for (int i = n1; i < n2; i++) {
            int sum = ((rhs.num[i] - '0') + carry);
            res.num.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
            res.num.push_back(carry + '0');
        if (flag)
            swap(num, rhs.num);
        reverse(res.num.begin(), res.num.end());
        reverse(num.begin(), num.end());
        reverse(rhs.num.begin(), rhs.num.end());
        res.clear();
        return res;
    }

    BigInteger operator+(short n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) +bi;
    }

    BigInteger operator+(int n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) +bi;
    }

    BigInteger operator+(long n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) +bi;
    }

    BigInteger operator+(ll n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) +bi;
    }

    BigInteger operator+(unsigned n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) +bi;
    }

    BigInteger operator+(unsigned long n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) +bi;
    }

    BigInteger operator+(unsigned long long n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -bi;
    }

    BigInteger operator-(short n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -bi;
    }

    BigInteger operator-(int n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -bi;
    }

    BigInteger operator-(long n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -bi;
    }

    BigInteger operator-(ll n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -bi;
    }

    BigInteger operator-(unsigned n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -bi;
    }

    BigInteger operator-(unsigned long n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -bi;
    }

    BigInteger operator-(unsigned long long n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -bi;
    }

    BigInteger operator-(BigInteger& rhs) {
        if (rhs.num[0] == '-') {
            BigInteger temp(rhs.num);
            temp.num.erase(temp.num.begin());
            return ((*this) + temp);
        }
        if (this->num[0] == '-') {
            BigInteger temp(num);
            temp.num.erase(temp.num.begin());
            temp += rhs;
            reverse(temp.num.begin(), temp.num.end());
            temp.num.push_back('-');
            reverse(temp.num.begin(), temp.num.end());
            return temp;
        }
        BigInteger res;
        bool flag = false;
        if ((*this) < rhs) {
            swap(num, rhs.num);
            flag = true;
        }
        int n1 = num.length(), n2 = rhs.num.length();
        int diff = n1 - n2;
        int carry = 0;
        for (int i = n2 - 1; i >= 0; i--) {
            int sub = ((num[i + diff] - '0') -
                    (rhs.num[i] - '0') -
                    carry);
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            } else
                carry = 0;
            res.num.push_back(sub + '0');
        }
        for (int i = n1 - n2 - 1; i >= 0; i--) {
            if (num[i] == '0' && carry) {
                res.num.push_back('9');
                continue;
            }
            int sub = ((num[i] - '0') - carry);
            if (i > 0 || sub > 0)
                res.num.push_back(sub + '0');
            carry = 0;
        }
        if (flag) {
            swap(num, rhs.num);
            res.num.push_back('-');
        }
        reverse(res.num.begin(), res.num.end());
        res.clear();
        return res;
    }

    BigInteger& operator+=(BigInteger& rhs) {
        BigInteger temp;
        temp = (*this) + rhs;
        this->num = temp.num;
        return *this;
    }

    BigInteger& operator+=(short n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) += bi;
    }

    BigInteger& operator+=(int n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) += bi;
    }

    BigInteger& operator+=(long n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) += bi;
    }

    BigInteger& operator+=(ll n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) += bi;
    }

    BigInteger& operator+=(unsigned int n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) += bi;
    }

    BigInteger& operator+=(unsigned long n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) += bi;
    }

    BigInteger& operator+=(unsigned long long n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) += bi;
    }

    BigInteger& operator-=(BigInteger& rhs) {
        BigInteger temp;
        temp = (*this) - rhs;
        this->num = temp.num;
        return *this;
    }

    BigInteger& operator-=(short n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -= bi;
    }

    BigInteger& operator-=(int n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -= bi;
    }

    BigInteger& operator-=(long n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -= bi;
    }

    BigInteger& operator-=(ll n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -= bi;
    }

    BigInteger& operator-=(unsigned int n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -= bi;
    }

    BigInteger& operator-=(unsigned long n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -= bi;
    }

    BigInteger& operator-=(unsigned long long n) {
        string temp = to_string(n);
        BigInteger bi(temp);
        return (*this) -= bi;
    }

    BigInteger& operator++(int) {
        BigInteger temp("1");
        *this += temp;
        return *this;
    }

    BigInteger& operator--(int) {
        BigInteger temp("1");
        *this -= temp;
        return *this;
    }

    BigInteger& operator++() {
        BigInteger temp("1");
        *this += temp;
        return *this;
    }

    BigInteger& operator--() {
        BigInteger temp("1");
        *this -= temp;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const BigInteger& obj) {
        for (int i = 0; i < obj.num.length(); i++)
            os << obj.num[i];
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& obj) {
        is >> obj.num;
        obj.clear();
        obj.trunc();
        return is;
    }

    ~BigInteger() {
    }
};

template <class T> class Matrix {
private:
    int row, col;
    T** data;
public:

    Matrix(int r, int c) {
        row = r;
        col = c;
        data = new T * [row];
        for (int i = 0; i < row; i++) {
            data[i] = new T[col];
            for (int j = 0; j < col; j++) {
                data[i][j] = 0;
            }
        }
    }

    int getRow() {
        return row;
    }

    int getCol() {
        return col;
    }

    Matrix<T> transpose() {
        Matrix<T> temp(col, row);

        for (int i = 0; i < temp.row; i++) {
            for (int j = 0; j < temp.col; j++) {
                temp.data[i][j] = this->data[j][i];
            }
        }
        return temp;
    }

    Matrix operator+(const Matrix& obj) {
        if (row != obj.row || col != obj.col) {
            cout << "Addition cannot be done!\n";
            return (*this);
        }
        Matrix<T> temp(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                temp.data[i][j] = this->data[i][j] + obj.data[i][j];
            }
        }
        return temp;
    }

    Matrix operator-(const Matrix& obj) {
        if (row != obj.row || col != obj.col) {
            cout << "Subtraction cannot be done!\n";
            return (*this);
        }
        Matrix<T> temp(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                temp.data[i][j] = this->data[i][j] - obj.data[i][j];
            }
        }
        return temp;
    }

    Matrix operator=(const Matrix& obj) {

        Matrix<T> temp(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                temp.data[i][j] = obj.data[i][j];
            }
        }
        return temp;
    }

    Matrix operator*(const Matrix& obj) {
        Matrix<T> temp(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < col; ++k) {
                    temp.data[i][j] += this->data[i][k] * obj.data[k][j];
                }
            }
        }
        return temp;
    }

    friend ostream& operator<<(ostream& os, const Matrix<T>& obj) {
        for (int i = 0; i < obj.row; i++) {
            os << endl;
            for (int j = 0; j < obj.col; j++)
                os << obj.data[i][j] << "  ";
        }
        return os;
    }

    friend istream& operator>>(istream& is, Matrix& obj) {
        for (int i = 0; i < obj.row; i++)
            for (int j = 0; j < obj.col; j++) {
                cout << "Enter element: " << i + 1 << "," << j + 1 << ": ";
                is >> obj.data[i][j];
            }
        return is;
    }

    /*~Matrix() {
        for (int i = 0; i < row; i++) {
                delete[] data[i];
        }
        delete[] data;
    }*/
};

int main() {
    
    
    
    // Testing the classes
    /*BigInteger a("17825698745636589515252541"), b(155889661477LL);
    if (a < b) cout << "less than\n";
    if (a > b) cout << "greater than\n";
    if (a <= b) cout << "less than or equal\n";
    if (a >= b) cout << "greater than or equal\n";
    if (a == b) cout << "equal\n";
    if (a != b) cout << "not equal\n";
    cout << a + b << " " << a - b << endl;
    a += b;
    cout << a << endl;
    a -= b;
    cout << a << endl;
    b++;
    cout << b << endl;
    cout << --b << endl;
    cout << a + 140 << " " << b - 11LL << endl;
    Matrix<BigInteger> m(3, 3);
    cin>>m;
    cout << m + m << '\n';
    cout << m.transpose() << '\n';
    cout << (a > 15 ? "true\n" : "false\n");*/
    return 0;
}