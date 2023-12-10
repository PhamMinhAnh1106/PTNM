
#include"ThuVien.h"
void main()
{

	int menu, vitri;
	hangHoa hh;
	dsHangHoa ds;
	do {
		cout << "|-----------------------------------------------|" << endl;
		cout << "|		MENU				|" << endl;
		cout << "|	1.Nhap thong tin hang hoa.		|" << endl;
		cout << "|	2.Xuat thong tin hang hoa.		|" << endl;
		cout << "|	3.Them thong tin hang hoa.		|" << endl;
		cout << "|	4.Sua thong tin hang hoa.		|" << endl;
		cout << "|	5.xoa thong tin hang hoa.		|" << endl;
		cout << "|	6.sap xep thong tin hang hoa.		|" << endl;
		cout << "|-----------------------------------------------|" << endl;
		cout << "   Nhap lua chon cua ban: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			nhapdsHH(ds);
			system("pause");
			break;
		case 2:
			xuatdsHH(ds);
			system("pause");
			break;
		case 3:
			nhapThongTinHH(hh);
			themHH(ds, hh);
			system("pause");
			break;
		case 4:
			suaHH(ds, hh);
			system("pause");
			break;
		case 5:
			xoaHH(ds, hh);
			system("pause");
			break;
		case 6:
			sapXepHHtheoMHH(ds);
			system("pause");
			break;
		default:
			cout << "Khong co trong menu!!" << endl;
			system("pause");
			break;
		}
	} while (menu != 99);
}