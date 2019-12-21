#include <iostream>
#include "solve.h"
#include "fltk/Graph.h"
#include "fltk/Simple_window.h"
#include "graph_utils.h"
using namespace std;

#define SHOW_INFO

int main() {
#ifdef SHOW_INFO
	cout << "��ӭʹ�ã����ڽ������ݶ�ȡ����ȴ�..." << endl;
	cout << endl << "��ȡÿ������" << endl;
#endif // SHOW_INFO
	// Read Data
	Data_Reader day_data("day.csv", 1);
	day_data.process_data();
#ifdef SHOW_INFO
	cout << "ÿ�����ݶ�ȡ��ɣ�" << endl;
	cout << endl << "��ȡÿСʱ����" << endl;
#endif // SHOW_INFO
	Data_Reader hour_data("hour.csv", 2);
	hour_data.process_data();
#ifdef SHOW_INFO
	cout << "ÿСʱ���ݶ�ȡ��ɣ�" << endl;
	cout << endl << "����һ�²˵���ѡ����Ҫ���еĲ���:\n____________________________________________" << endl;
#endif // SHOW_INFO

	while (true) {
		cout << endl << "1�����ӻ���\n2������Ԥ�⡣\n3���˳���\n����������ѡ�����:";
		int input;
		cin >> input;

		if (input == 1) {
			cout << endl << "1��ÿ����ʹ��������ͼ��\n2��ÿ�ո����ʹ��������ͼ��\n3���û���������״ͼ��\n4���û��������仯����ͼ��\n5��ÿ�ܸ�������ռ�ȱ���ͼ��\n6��ÿ���ʱ��ƽ��ʹ��������ͼ��\n7����ͬ�¶�ʹ��������ͼ��\n8����ͬʪ��ʹ��������ͼ��\n9����ͬ��������ʹ��������ͼ��\n10����������ǹ������������ͼ��\n����������ѡ��";
			cin >> input;
			if (input == 1) {
				Show_Data show_data(day_data);
				show_data.show_year_graph1();
			}
			else if (input == 2) {
				Show_Data show_data(day_data);
				show_data.show_year_graph2();
			}
			else if (input == 3) {
				Show_Data show_data(day_data);
				show_data.show_pie_chart1();
			}
			else if (input == 4) {
				Show_Data show_data(day_data);
				show_data.show_proportion_chart1();
			}
			else if (input == 5) {
				Show_Data show_data(day_data);
				show_data.show_proportion_chart2();
			}
			else if (input == 6) {
				Show_Data show_data(hour_data);
				show_data.show_day_graph1();
			}
			else if (input == 7) {
				Show_Data show_data(day_data);
				show_data.show_temp_chart1();
			}
			else if (input == 8) {
				Show_Data show_data(day_data);
				show_data.show_hum_chart1();
			}
			else if (input == 9) {
				Show_Data show_data(day_data);
				show_data.show_bar_chart1();
			}
			else if (input == 10) {
				Show_Data show_data(day_data);
				show_data.show_bar_chart2();
			}
		}
		else if (input == 2) {
			cout << endl << "��ע�⣬����ѵ��ʹ�������磬���Կ�������ʱ��ϳ���2�������ң�\n������ϸ���ú�ѡ��\n1��������ֲ��Լ���ѵ������Ԥ��ÿ���û���\n2��ǰ�߸�������Ϊѵ��������һ��������Ϊ���Լ���Ԥ��ÿ���û���\n3��������ֲ��Լ���ѵ������Ԥ��ÿСʱ�û���\n����������ѡ��";
			cin >> input;
			if (input == 1) {
				Data_Analyzer analyzer(day_data, 1);
				cout << "��ʼʹ����С���˷�ѵ��..." << endl;
				analyzer.linear_regression();
				auto loss1 = analyzer.check_accuracy();
				cout << "ѵ����ɡ�\n\nʹ��������ѵ��..." << endl;
				analyzer.nerual_network();
				auto loss2 = analyzer.check_accuracy();
				cout << endl << "ѵ����ɣ���С���˷��������Ϊ" << loss1 << "��������������Ϊ" << loss2 << endl;
			}
			else if (input == 2) {
				Data_Analyzer analyzer(day_data, 3);
				cout << "��ʼʹ����С���˷�ѵ��..." << endl;
				analyzer.linear_regression();
				auto loss1 = analyzer.check_accuracy();
				cout << "ѵ����ɡ�\n\nʹ��������ѵ��..." << endl;
				analyzer.nerual_network();
				auto loss2 = analyzer.check_accuracy();
				cout << endl << "ѵ����ɣ���С���˷��������Ϊ" << loss1 << "��������������Ϊ" << loss2 << endl;
			}
			else {
				Data_Analyzer analyzer(hour_data, 2);
				cout << "��ʼʹ����С���˷�ѵ��..." << endl;
				analyzer.linear_regression();
				auto loss1 = analyzer.check_accuracy();
				cout << "ѵ����ɡ�\n\nʹ��������ѵ��..." << endl;
				analyzer.nerual_network();
				auto loss2 = analyzer.check_accuracy();
				cout << endl << "ѵ����ɣ���С���˷��������Ϊ" << loss1 << "��������������Ϊ" << loss2 << endl;
			}
		}
		else {
			break;
		}
	}

	return 0;
}
