#include<iostream>

using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }
    Circle(int r) { radius = r; }
    ~Circle(){}
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14 * radius * radius; }
};

int main() {
    cout << "원의 개수 >> ";
    int n, radius,count=0;
    cin >> n; //원의 개수 입력

    Circle* pArray = new Circle[n]; // n개의 Circle 배열 생성
    for (int i = 0;i <n;i++)
    {
        cout << "원" << i + 1 << "의 반지름 >> ";
        cin >> radius;
        pArray[i].setRadius(radius); // 각 Circle 객체를 반지름으로 초기화
        if (pArray[i].getArea() > 100)
        {
            count++;
        }
    }
    cout << "면적이 100보다 큰 원은 " << count << "개 입니다." << endl;

    delete[] pArray;

    return 0;
}