#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
const int MAX = 100;
struct hangHoa
{
	char maHangHoa[20];
	char tenHangHoa[20];
	int ngaySanXuat;
	int thangSanXuat;
	int namSanXuat;
	int soLuong;
	double gia;
};

struct dsHangHoa
{
	int n;
	hangHoa danhSach[MAX];
};

void time(int& day, int& month, int& year);

void nhapThongTinHH(hangHoa &n);
void xuatThongTinHH(hangHoa n);

void nhapdsHH(dsHangHoa &ds);
void xuatdsHH(dsHangHoa ds);

void themHH(dsHangHoa& ds, hangHoa& hh); void themHHtaiViTri(dsHangHoa& ds, hangHoa& hh, int vitri);
bool kiemTraHH(dsHangHoa ds, hangHoa key);

void suaHH(dsHangHoa& ds, hangHoa& hh);
void xoaHH(dsHangHoa& ds, hangHoa& hh);

void sapXepHHtheoMHH(dsHangHoa& ds);

