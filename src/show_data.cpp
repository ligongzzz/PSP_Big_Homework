#include "graph_utils.h"
#include <iostream>
#include <vector>
#include <map>
#include "fltk/Graph.h"
#include "fltk/Simple_window.h"
#include "solve.h"
#include <algorithm>
using namespace std;

void Show_Data::show_year_graph1() const {
	Simple_window win(Point(100, 100), 900, 600, u8"ÿ��ʹ�ô���");
	
	//Draw the back ground.
	Graph_lib::Rectangle rect(Point(0, 0), Point(800, 600));
	rect.set_fill_color(0xffffff00);
	win.attach(rect);

	//Draw the title.
	Graph_lib::Text text(Point(300, 100), u8"2011����2013��ÿ�����û���");
	text.set_color(0);
	text.set_font_size(20);
	win.attach(text);

	//Draw the line chart.
	Line_Chart chart(100, 500, 600, 400, 5, 6);
	chart.set_range(0, data.processed_data.size(), 0, 10000);
	chart.set_label({ u8"2011��",u8"2011��",u8"2012��",u8"2012��",u8"2013��" }, { "0","2000","4000","6000","8000","10000" });
	vector<pair<double, double>> sdata;
	for (size_t i = 0; i < data.processed_data.size(); ++i) {
		sdata.emplace_back(make_pair(double(i), double(data.processed_data[i].total_cnt)));
	}
	chart.add_data(sdata);
	
	//Show the window.
	win.attach(chart);
	win.wait_for_button();
}

void Show_Data::show_year_graph2() const {
	Simple_window win(Point(100, 100), 900, 600, u8"ÿ��ʹ�ô���(���û�����)");

	//Draw the back ground.
	Graph_lib::Rectangle rect(Point(0, 0), Point(800, 600));
	rect.set_fill_color(0xffffff00);
	win.attach(rect);

	//Draw the title.
	Graph_lib::Text text(Point(200, 100), u8"2011����2013��ÿ���û���(�����û����)");
	text.set_color(0);
	text.set_font_size(20);
	win.attach(text);

	//Draw the line chart.
	Line_Chart chart(100, 500, 600, 400, 5, 6);
	chart.set_range(0, data.processed_data.size(), 0, 10000);
	chart.set_label({ u8"2011��",u8"2011��",u8"2012��",u8"2012��",u8"2013��" }, { "0","2000","4000","6000","8000","10000" });
	vector<pair<double, double>> sdata1, sdata2, sdata3;
	for (size_t i = 0; i < data.processed_data.size(); ++i) {
		sdata1.emplace_back(make_pair(double(i), double(data.processed_data[i].total_cnt)));
		sdata2.emplace_back(make_pair(double(i), double(data.processed_data[i].registered)));
		sdata3.emplace_back(make_pair(double(i), double(data.processed_data[i].casual)));
	}
	chart.add_data(sdata1, u8"�����û�");
	chart.add_data(sdata2, u8"δע���û�");
	chart.add_data(sdata3, u8"ע���û�");
	chart.show_line_label = true;

	//Show the window.
	win.attach(chart);
	win.wait_for_button();
}

void Show_Data::show_loss_chart1(double dat1, const vector<double>& dat2) const {
	Simple_window win(Point(100, 100), 900, 600, u8"��ʧ�仯");

	//Draw the back ground.
	Graph_lib::Rectangle rect(Point(0, 0), Point(800, 600));
	rect.set_fill_color(0xffffff00);
	win.attach(rect);

	//Draw the title.
	Graph_lib::Text text(Point(300, 100), u8"��ʧ��ѵ�������仯");
	text.set_color(0);
	text.set_font_size(20);
	win.attach(text);

	//Draw the line chart.
	Line_Chart chart(100, 500, 600, 400, 6, 6);
	chart.set_range(0, dat2.size(), 0, 1);
	chart.set_label({ "0","200","400","600","800","1000" }, { "0","0.2","0.4","0.6","0.8","1.0" });
	vector<pair<double, double>> sdata1, sdata2;
	for (size_t i = 0; i < dat2.size(); ++i) {
		sdata1.emplace_back(make_pair(i, dat1));
		sdata2.emplace_back(make_pair(i, dat2[i]));
	}
	chart.add_data(sdata1, u8"��С���˷�");
	chart.add_data(sdata2, u8"������");
	chart.show_line_label = true;

	//Show the window.
	win.attach(chart);
	win.wait_for_button();
}

void Show_Data::show_loss_chart2(const vector<double>& real, 
	const vector<double>& pred1, const vector<double>& pred2) const {
	Simple_window win(Point(100, 100), 900, 600, u8"Ԥ��Ƚ�");

	//Draw the back ground.
	Graph_lib::Rectangle rect(Point(0, 0), Point(800, 600));
	rect.set_fill_color(0xffffff00);
	win.attach(rect);

	//Draw the title.
	Graph_lib::Text text(Point(300, 100), u8"Ԥ����������ʵ���ݱȽ�");
	text.set_color(0);
	text.set_font_size(20);
	win.attach(text);

	//Draw the line chart.
	Line_Chart chart(100, 500, 600, 400, 6, 6);
	chart.set_range(0, real.size(), 0, 1000);
	chart.set_label({ "0",
		to_string(int(real.size() * 0.2)),
		to_string(int(real.size() * 0.4)),
		to_string(int(real.size() * 0.6)),
		to_string(int(real.size() * 0.8)),
		to_string(int(real.size() * 1.0)) }, 
		{ "0","200","400","600","800","1000" });
	vector<pair<double, double>> sdata1, sdata2, sdata3;
	for (size_t i = 0; i < real.size(); ++i) {
		sdata1.emplace_back(make_pair(i, real[i]));
		sdata2.emplace_back(make_pair(i, pred1[i]));
		sdata3.emplace_back(make_pair(i, pred2[i]));
	}
	chart.add_data(sdata1, u8"��ʵ����");
	chart.add_data(sdata2, u8"��С���˷�");
	chart.add_data(sdata3, u8"������");
	chart.show_line_label = true;

	//Show the window.
	win.attach(chart);
	win.wait_for_button();
}

void Show_Data::show_pie_chart1() const {
	Simple_window win(Point(100, 100), 900, 600, u8"�����û�����ռ��");

	//Draw the back ground.
	Graph_lib::Rectangle rect(Point(0, 0), Point(800, 600));
	rect.set_fill_color(0xffffff00);
	win.attach(rect);

	//Draw the title.
	Graph_lib::Text text(Point(300, 50), u8"�����û�����ռ��");
	text.set_color(0);
	text.set_font_size(20);
	win.attach(text);

	//Calcultate the data.
	int casual_cnt = 0, registered_cnt = 0;
	for (auto p : data.processed_data) {
		casual_cnt += p.casual;
		registered_cnt += p.registered;
	}

	Pie_Chart chart(400, 300, 200);
	chart.set_data(vector<int>{ casual_cnt, registered_cnt });
	chart.set_label({ u8"δע���û�",u8"ע���û�" });
	
	win.attach(chart);
	win.wait_for_button();
}

void Show_Data::show_proportion_chart1() const {
	Simple_window win(Point(100, 100), 1100, 600, u8"�����û�����ռ��");

	//Draw the back ground.
	Graph_lib::Rectangle rect(Point(0, 0), Point(1000, 600));
	rect.set_fill_color(0xffffff00);
	win.attach(rect);

	//Draw the title.
	Graph_lib::Text text(Point(300, 50), u8"�����û�����ռ��");
	text.set_color(0);
	text.set_font_size(20);
	win.attach(text);

	Proportion_Chart chart(100, 500, 600, 400, 5, 2);
	chart.set_range(0, data.processed_data.size());
	chart.show_line_label = true;
	chart.set_label({ u8"δע���û�",u8"��ע���û�" });
	chart.set_x_label({ u8"2011��",u8"2011��",u8"2012��",u8"2012��",u8"2013��" });
	
	chart.add_data(0, { (double)data.processed_data[0].casual,
		(double)data.processed_data[0].registered });
	for (int i = 0, casual = 0, registered = 0, month = 1;
		i < data.processed_data.size(); ++i) {
		casual += data.processed_data[i].casual;
		registered += data.processed_data[i].registered;
		
		if (data.processed_data[i].month != month || i == data.processed_data.size() - 1) {
			month = data.processed_data[i].month;
			chart.add_data(i, { (double)casual,(double)registered });
			casual = registered = 0;
		}
	}

	chart.process_data();

	//Show the window.
	win.attach(chart);
	win.wait_for_button();
}

void Show_Data::show_proportion_chart2() const {
	Simple_window win(Point(100, 100), 1300, 700, u8"ÿ�ܸ�������ռ��");

	//Draw the back ground.
	Graph_lib::Rectangle rect(Point(0, 0), Point(1200, 700));
	rect.set_fill_color(0xffffff00);
	win.attach(rect);

	//Draw the title.
	Graph_lib::Text text(Point(500, 50), u8"ÿ�ܸ�������ռ��");
	text.set_color(0);
	text.set_font_size(30);
	win.attach(text);

	Proportion_Chart chart(100, 600, 800, 500, 5, 7);
	chart.set_range(0, data.processed_data.size());
	chart.show_line_label = true;
	chart.set_label({ u8"������",u8"����һ",u8"���ڶ�",u8"������",u8"������",u8"������",u8"������" });
	chart.set_x_label({ u8"2011��",u8"2011��",u8"2012��",u8"2012��",u8"2013��" });
	
	vector<double> adata;
	for (int i = 1; i < data.processed_data.size(); ++i) {
		adata.emplace_back(data.processed_data[i].total_cnt);
		if (i % 7 == 0) {
			chart.add_data(i - 7, adata);
			adata.clear();
		}
	}

	chart.process_data();

	//Show the window.
	win.attach(chart);
	win.wait_for_button();
}

void Show_Data::show_day_graph1() const {
	Simple_window win(Point(100, 100), 900, 600, u8"��Сʱ�û�����");

	//Draw the back ground.
	Graph_lib::Rectangle rect(Point(0, 0), Point(800, 600));
	rect.set_fill_color(0xffffff00);
	win.attach(rect);

	//Draw the title.
	Graph_lib::Text text(Point(300, 100), u8"��Сʱƽ���û�����");
	text.set_color(0);
	text.set_font_size(20);
	win.attach(text);

	//Draw the line chart.
	Line_Chart chart(100, 500, 600, 400, 5, 6);
	chart.set_range(0, 24, 0, 500);
	chart.set_label({ "0","6","12","18","24" }, { "0","100","200","300","400","500" });
	vector<pair<double,double>> casual(24), registered(24), total(24);
	vector<int> cnt(24, 0);
	for (int i = 0; i < 24; ++i) {
		casual[i] = make_pair((double)i, 0.0);
		registered[i] = make_pair((double)i, 0.0);
		total[i] = make_pair((double)i, 0.0);
	}
	for (size_t i = 0; i < data.processed_data.size(); ++i) {
		casual[data.processed_data[i].hour].second += (double)data.processed_data[i].casual;
		registered[data.processed_data[i].hour].second += (double)data.processed_data[i].registered;
		total[data.processed_data[i].hour].second += (double)data.processed_data[i].total_cnt;
		++cnt[data.processed_data[i].hour];
	}
	for (int i = 0; i < 24; ++i) {
		casual[i].second /= cnt[i];
		registered[i].second /= cnt[i];
		total[i].second /= cnt[i];
	}
	chart.add_data(casual,u8"δע���û�");
	chart.add_data(registered, u8"��ע���û�");
	chart.add_data(total, u8"���û�");
	chart.show_line_label = true;

	//Show the window.
	win.attach(chart);
	win.wait_for_button();
}

void Show_Data::show_bar_chart1() const {
	Simple_window win(Point(100, 100), 900, 600, u8"��ͬ�����û�����");

	//Draw the back ground.
	Graph_lib::Rectangle rect(Point(0, 0), Point(800, 600));
	rect.set_fill_color(0xffffff00);
	win.attach(rect);

	//Draw the title.
	Graph_lib::Text text(Point(300, 100), u8"��ͬ����ƽ���û�����");
	text.set_color(0);
	text.set_font_size(20);
	win.attach(text);

	//Draw the bar chart.
	Bar_Chart chart(100, 150, 600, 400);
	
	vector<double> num(3, 0.0);
	vector<int> cnt(3, 0);

	for (auto p : data.processed_data) {
		num[static_cast<int>(p.weather)] += p.total_cnt;
		cnt[static_cast<int>(p.weather)] ++;
	}

	chart.add_data(num[0] / cnt[0], u8"����");
	chart.add_data(num[1] / cnt[1], u8"����");
	chart.add_data(num[2] / cnt[2], u8"��ѩ");

	//Show the window.
	win.attach(chart);
	win.wait_for_button();
}

void Show_Data::show_bar_chart2() const {
	Simple_window win(Point(100, 100), 900, 600, u8"��������ǹ������û�����");

	//Draw the back ground.
	Graph_lib::Rectangle rect(Point(0, 0), Point(800, 600));
	rect.set_fill_color(0xffffff00);
	win.attach(rect);

	//Draw the title.
	Graph_lib::Text text(Point(300, 100), u8"��������ǹ������û�����");
	text.set_color(0);
	text.set_font_size(20);
	win.attach(text);

	//Draw the bar chart.
	Bar_Chart chart(250, 150, 300, 400);

	vector<double> num(2, 0.0);
	vector<int> cnt(2, 0);

	for (auto p : data.processed_data) {
		num[static_cast<int>(p.workingday)] += p.total_cnt;
		cnt[static_cast<int>(p.workingday)] ++;
	}

	chart.add_data(num[0] / cnt[0], u8"�ǹ�����");
	chart.add_data(num[1] / cnt[1], u8"������");

	//Show the window.
	win.attach(chart);
	win.wait_for_button();
}

void Show_Data::show_temp_chart1() const {
	Simple_window win(Point(100, 100), 900, 600, u8"��ͬ�¶��û�����");

	//Draw the back ground.
	Graph_lib::Rectangle rect(Point(0, 0), Point(800, 600));
	rect.set_fill_color(0xffffff00);
	win.attach(rect);

	//Draw the title.
	Graph_lib::Text text(Point(300, 100), u8"��ͬ�¶��û�����");
	text.set_color(0);
	text.set_font_size(20);
	win.attach(text);

	//Draw the line chart.
	Line_Chart chart(100, 500, 600, 400, 6, 6);
	chart.set_range(0, 1, 0, 10000);
	chart.set_label({ u8"0��",u8"10��",u8"20��",u8"30��",u8"40��",u8"50��" }, { "0","2000","4000","6000","8000","10000" });
	vector<pair<double, double>> sdata;
	for (size_t i = 0; i < data.processed_data.size(); ++i) {
		sdata.emplace_back(make_pair(data.processed_data[i].temperature, double(data.processed_data[i].total_cnt)));
	}
	sort(sdata.begin(), sdata.end(), [](auto a, auto b) {return a.first < b.first; });
	chart.add_data(sdata);

	//Show the window.
	win.attach(chart);
	win.wait_for_button();
}

void Show_Data::show_hum_chart1() const {
	Simple_window win(Point(100, 100), 900, 600, u8"��ͬʪ���û�����");

	//Draw the back ground.
	Graph_lib::Rectangle rect(Point(0, 0), Point(800, 600));
	rect.set_fill_color(0xffffff00);
	win.attach(rect);

	//Draw the title.
	Graph_lib::Text text(Point(300, 100), u8"��ͬʪ���û�����");
	text.set_color(0);
	text.set_font_size(20);
	win.attach(text);

	//Draw the line chart.
	Line_Chart chart(100, 500, 600, 400, 6, 6);
	chart.set_range(0, 1, 0, 10000);
	chart.set_label({ u8"0",u8"20",u8"40",u8"60",u8"80",u8"100" }, { "0","2000","4000","6000","8000","10000" });
	vector<pair<double, double>> sdata;
	for (size_t i = 0; i < data.processed_data.size(); ++i) {
		sdata.emplace_back(make_pair(data.processed_data[i].hum, double(data.processed_data[i].total_cnt)));
	}
	sort(sdata.begin(), sdata.end(), [](auto a, auto b) {return a.first < b.first; });
	chart.add_data(sdata);

	//Show the window.
	win.attach(chart);
	win.wait_for_button();
}
