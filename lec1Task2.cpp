#include <iostream>
#include <iomanip>
using namespace std;

struct ToaDo { double x, y; };
double DinhMenh(ToaDo a, ToaDo b, ToaDo c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool CoGiao(ToaDo a, ToaDo b, ToaDo c, ToaDo d) {
    return DinhMenh(a, b, c) * DinhMenh(a, b, d) < 0 &&
           DinhMenh(c, d, a) * DinhMenh(c, d, b) < 0;
}
ToaDo GiaoDiem(ToaDo a, ToaDo b, ToaDo c, ToaDo d) {
    double A1 = b.y - a.y, B1 = a.x - b.x, C1 = A1 * a.x + B1 * a.y;
    double A2 = d.y - c.y, B2 = c.x - d.x, C2 = A2 * c.x + B2 * c.y;
    double D = A1 * B2 - A2 * B1;
    return { (C1 * B2 - C2 * B1) / D, (A1 * C2 - A2 * C1) / D };
}
int main() {
    ToaDo p[4];
    for (auto &i : p) cin >> i.x >> i.y;
    if (CoGiao(p[0], p[1], p[2], p[3])) {
        ToaDo giao = GiaoDiem(p[0], p[1], p[2], p[3]);
        cout << fixed << setprecision(2) << giao.x << " " << giao.y << endl;
    } else {
        cout << "NO" << endl;
    }
}
