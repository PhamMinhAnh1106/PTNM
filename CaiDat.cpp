#define _CRT_SECURE_NO_WARNINGS
#include"ThuVien.h"
void time(int& day, int& month, int& year)
{
	time_t now = time(0);
	tm* timeinfo = localtime(&now);
	year = 1900 + timeinfo->tm_year;
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon + 1;
}

void nhapThongTinHH(hangHoa& n)
{
	int day, month, year;
	time(day, month, year);
	cin.ignore();
	cout << "Ma hang hoa: ";
	cin.getline(n.maHangHoa, 20);
	cout << "Ten hang hoa: ";
	cin.getline(n.tenHangHoa, 20);
	cout << "Thoi gian san xuat (dd/mm/yyyy): " << endl;
	bool thoiGianHopLe = false;
	while (!thoiGianHopLe)
	{
		cout << "	-Ngay: ";
		cin >> n.ngaySanXuat;
		cout << "	-Thang: ";
		cin >> n.thangSanXuat;
		cout << "	-Nam: ";
		cin >> n.namSanXuat;
		if (n.ngaySanXuat >= 1 && n.ngaySanXuat <= day && n.thangSanXuat >= 1 && n.thangSanXuat == month && n.namSanXuat >= 1 && n.namSanXuat <= year 
		|| n.ngaySanXuat >= 1 && n.ngaySanXuat <= 31 && n.thangSanXuat >= 1 && n.thangSanXuat < month && n.namSanXuat >= 1 && n.namSanXuat <= year
		|| n.ngaySanXuat >= 1 && n.ngaySanXuat <= 31 && n.thangSanXuat >= 1 && n.thangSanXuat <=12 && n.namSanXuat >= 1 && n.namSanXuat < year)
			thoiGianHopLe = true;
		else
			cout << "Thoi gian khong hop le! Vui long nhap lai.\n";
	}
	cout << "So luong: ";
	cin >> n.soLuong;
	cout << "Gia: ";
	cin >> n.gia;
}


void xuatThongTinHH(hangHoa n)
{
	//cout << n.maHangHoa << setw(20) << n.tenHangHoa << setw(20) << n.ngaySanXuat << setw(10) << n.soLuong << setw(10) << n.gia;

	cout << n.maHangHoa;
	cout << setw(30) << n.tenHangHoa;
	cout << setw(30) << n.ngaySanXuat << "/" << n.thangSanXuat << "/" << n.namSanXuat;
	cout << setw(30) << n.soLuong;
	cout << setw(30) << n.gia;

}

void nhapdsHH(dsHangHoa& ds)
{
	cout << "So luong hang hoa muon nhap: ";
	cin >> ds.n;
	for (int i = 0; i < ds.n; i++)
		nhapThongTinHH(ds.danhSach[i]);
}
void xuatdsHH(dsHangHoa ds)
{
	cout << "Ma hang hoa" << setw(30) << "Ten hang hoa" << setw(30) << "Ngay san xuat" << setw(30) << "So luong" << setw(30) << "Gia" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < ds.n; i++)
	{
		xuatThongTinHH(ds.danhSach[i]);
		cout << endl;
	}
}


void themHH(dsHangHoa& ds, hangHoa& hh)
{
	bool THEMHH = false;
	do
	{
		if (!kiemTraHH(ds, hh))
			/*for (int i = ds.n; i > vitri; i--)
			{
				ds.danhSach[i] = ds.danhSach[i - 1];
			}*/
		{
			strcpy(ds.danhSach[ds.n].maHangHoa, hh.maHangHoa);
			strcpy(ds.danhSach[ds.n].tenHangHoa, hh.tenHangHoa);
			ds.danhSach[ds.n].ngaySanXuat = hh.ngaySanXuat;
			ds.danhSach[ds.n].thangSanXuat = hh.thangSanXuat;
			ds.danhSach[ds.n].namSanXuat = hh.namSanXuat;
			ds.danhSach[ds.n].soLuong = hh.soLuong;
			ds.danhSach[ds.n].gia = hh.gia;
			ds.n++;
			THEMHH = true;
		}
		else
		{
			cout << "Khong hop le!";
			THEMHH = false;
		}
	} while (!THEMHH);
}




bool kiemTraHH(dsHangHoa ds, hangHoa key)
{
	bool kt = false;
	for (int i = 0; i < ds.n; i++)
	{
		if (strcmp(ds.danhSach[i].maHangHoa, key.maHangHoa) == 0)
		{
			kt = true;
			break;
		}
	}
	return kt;
}

void suaHH(dsHangHoa& ds, hangHoa& hh)
{
	bool TimTheo = false;
	char timTheo[20];
	do {
		cin.ignore();
		cout << "Nhap ma hang hoa hoac ten hang hoa muon sua: ";
		cin.getline(timTheo, 20);
		int vitriFix = -1;
		for (int i = 0; i < ds.n; i++) {
			if (strcmp(ds.danhSach[i].maHangHoa, timTheo) == 0 || strcmp(ds.danhSach[i].tenHangHoa, timTheo) == 0) {
				vitriFix = i;
				break;
			}
		}

		if (vitriFix != -1)
		{
			cout << "Thong tin hang hoa truoc khi sua:\n";
			xuatThongTinHH(ds.danhSach[vitriFix]);
			cout << endl;
			nhapThongTinHH(ds.danhSach[vitriFix]);
			cout << endl;
			TimTheo = true;
		}
		else {
			cout << "Khong tim thay mat hang voi ma hoac ten la [" << timTheo <<"]" << endl;
			TimTheo = false;
		}
	} while (!TimTheo);
}

void xoaHH(dsHangHoa& ds, hangHoa& hh)
{
	bool TimTheo = false;
	char timTheo[20];
	do {
		cin.ignore();
		cout << "Nhap ma hang hoa hoac ten hang hoa muon xoa: ";
		cin.getline(timTheo, 20);
		int vitriFix = -1;
		for (int i = 0; i < ds.n; i++) {
			if (strcmp(ds.danhSach[i].maHangHoa, timTheo) == 0 || strcmp(ds.danhSach[i].tenHangHoa, timTheo) == 0) {
				vitriFix = i;
				break;
			}
		}
		if (vitriFix != -1)
		{
			for (int i = vitriFix; i < ds.n; i++)
				ds.danhSach[i] = ds.danhSach[i + 1];
			ds.n--;
			cout << "Xoa thanh cong!" << endl;
			TimTheo = true;
		}
		else
		{
			cout << "Khong hop le!" << endl;
			TimTheo = false;
		}
	} while (!TimTheo);
}

void sapXepHHtheoMHH(dsHangHoa& ds)
{
	if (ds.n > 1)
		for (int i = 0; i < ds.n - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < ds.n; j++)
			{
				//if (ds.danhSach[j].soLuong < ds.danhSach[min].soLuong)
				if (strcmp(ds.danhSach[j].maHangHoa, ds.danhSach[min].maHangHoa) < 0)
					min = j;
			}
			swap(ds.danhSach[i], ds.danhSach[min]);
			cout << "\nSap xep thanh cong!";
		}
	else
		cout << "\n Khong du thong tin hang hoa de sap xep!!";
}

