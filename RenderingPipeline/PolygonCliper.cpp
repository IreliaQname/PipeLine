#include "PolygonCliper.h"
#include <utility>


PolygonCliper::PolygonCliper()
{
}


PolygonCliper::~PolygonCliper()
{
}

void PolygonCliper::clip(std::vector<Point>& pointsIn, std::vector<Point>& bottom)
{
}

void PolygonCliper::clip(Object & object)
{
	if (object.planes.empty())
		return;
	for (auto& plane : object.planes) {
		if (plane.empty())
			continue;
		Plane left, right, top, bottom;
		int numArc = plane.size();
		for (int i = 0; i < numArc - 1; ++i) {
			const auto& p0 = plane[i];
			const auto& p1 = plane[i + 1];

			auto x0 = p0.x;
			auto y0 = p0.y;
			auto x1 = p1.x;
			auto y1 = p1.y;
			auto r0 = p0.r;
			auto r1 = p1.r;
			auto g0 = p0.g;
			auto g1 = p1.g;
			auto b0 = p0.b;
			auto b1 = p1.b;

			auto k = (y1 - y0) / (x1 - x0);  // б�ʣ���ʱ�������������
			auto kr = (r1 - r0) / (x1 - x0);
			auto kg = (g1 - g0) / (x1 - x0);
			auto kb = (b1 - b0) / (x1 - x0);

			double x = L;
			double y = 0.0;
			double z = 0.0;
			int r, g, b;

			// ���1
			if (x0<L&&x1>L) {
				y = k * (L - x1) + y1;
				r = kr * (L - x1) + r1;
				g = kg * (L - x1) + g1;
				b = kb * (L - x1) + b1;
				// ע���Z R G B�Ĳ�ֵ����
				left.emplace_back(Point(x, y, z, r, g, b));
				left.emplace_back(p1);
			}

			// ���2
			else if (x0 >= L && x1 >= L) {
				left.emplace_back(p1);
			}

			// ���3
			else if (x0 >= L && x1 < L) {
				y = k * (L - x1) + y1;
				r = kr * (L - x1) + r1;
				g = kg * (L - x1) + g1;
				b = kb * (L - x1) + b1;
				left.emplace_back(Point(x, y, z, r, g, b));
			}

			// ���4 �����ɼ�����������
		}
		if (!left.empty())
			left.push_back(left[0]);  // �γɷ��ͼ��

		// �����Ҳ�
		numArc = left.size();
		for (int i = 0; i < numArc - 1; ++i) {

			const auto& p0 = left[i];
			const auto& p1 = left[i + 1];
			auto x0 = p0.x;
			auto y0 = p0.y;
			auto x1 = p1.x;
			auto y1 = p1.y;
			auto r0 = p0.r;
			auto r1 = p1.r;
			auto g0 = p0.g;
			auto g1 = p1.g;
			auto b0 = p0.b;
			auto b1 = p1.b;

			auto k = (y1 - y0) / (x1 - x0);  // б�ʣ���ʱ�������������
			auto kr = (r1 - r0) / (x1 - x0);
			auto kg = (g1 - g0) / (x1 - x0);
			auto kb = (b1 - b0) / (x1 - x0);

			double x = R;
			double y = 0.0;
			double z = 0.0;
			int r, g, b;
			bool tag = false;    // �Ƿ񱻲ü�����
			// ���1�����ղ��͵����ӣ�p0���ɼ� p1�ɼ�
			if (x0 > R && x1 <= R) {
				y = k * (R - x1) + y1;
				r = kr * (R - x1) + r1;
				g = kg * (R - x1) + g1;
				b = kb * (R - x1) + b1;
				// ע���Z R G B�Ĳ�ֵ����
				right.emplace_back(Point(x, y, z, r, g, b));
				right.emplace_back(p1);
			}
			// ���2  p0��p1���ɼ�
			else if (x0 <= R && x1 <= R) {
				right.emplace_back(p1);
			}
			// ���3  p0�ɼ� p1���ɼ�
			else if (x0 <= R && x1 > R) {
				y = k * (R - x1) + y1;
				r = kr * (R - x1) + r1;
				g = kg * (R - x1) + g1;
				b = kb * (R - x1) + b1;
				right.emplace_back(Point(x, y, z, r, g, b));
			}
			// ���4�����ɼ����������κδ���
		}

		// ��Ļ�ϲ�ı߲ü�
		if (!right.empty())
			right.push_back(right[0]); // ���ɷ��ͼ��
		numArc = right.size();
		for (int i = 0; i < numArc - 1; ++i) {

			const auto& p0 = right[i];
			const auto& p1 = right[i + 1];
			auto x0 = p0.x;
			auto y0 = p0.y;
			auto x1 = p1.x;
			auto y1 = p1.y;
			auto r0 = p0.r;
			auto r1 = p1.r;
			auto g0 = p0.g;
			auto g1 = p1.g;
			auto b0 = p0.b;
			auto b1 = p1.b;

			auto k = (x1 - x0) / (y1 - y0);  // б�ʣ���ʱ�������������
			auto kr = (r1 - r0) / (y1 - y0);
			auto kg = (g1 - g0) / (y1 - y0);
			auto kb = (b1 - b0) / (y1 - y0);

			double x = 0.0;
			double y = T;
			double z = 0.0;
			int r, g, b;
			bool tag = false;    // �Ƿ񱻲ü�����
			// ���1�����ղ��͵����ӣ�
			if (y0 > T && y1 <= T) {
				x = k * (T - y1) + x1;
				r = kr * (T - y0) + r0;
				g = kg * (T - y0) + g0;
				b = kb * (T - y0) + b0;
				// ע���Z R G B�Ĳ�ֵ����
				top.emplace_back(Point(x, y, z, r, g, b));
				top.emplace_back(p1);
			}
			// ���2
			else if (y0 <= T && y1 <= T) {
				top.emplace_back(p1);
			}
			// ���3
			else if (y0 <= T && y1 > T) {
				x = k * (T - y1) + x1;
				r = kr * (T - y1) + r1;
				g = kg * (T - y1) + g1;
				b = kb * (T - y1) + b1;
				top.emplace_back(Point(x, y, z, r, g, b));
			}
			// ���4�����ɼ����������κδ���
		}

		// ��Ļ�²�ı߲ü�
		if (!top.empty())
			top.push_back(top[0]);  // ���ɷ��ͼ��
		numArc = top.size();
		for (int i = 0; i < numArc - 1; ++i) {

			const auto& p0 = top[i];
			const auto& p1 = top[i + 1];
			auto x0 = p0.x;
			auto y0 = p0.y;
			auto x1 = p1.x;
			auto y1 = p1.y;
			auto r0 = p0.r;
			auto r1 = p1.r;
			auto g0 = p0.g;
			auto g1 = p1.g;
			auto b0 = p0.b;
			auto b1 = p1.b;

			auto k = (x1 - x0) / (y1 - y0);  // б�ʣ���ʱ�������������
			auto kr = (r1 - r0) / (y1 - y0);
			auto kg = (g1 - g0) / (y1 - y0);
			auto kb = (b1 - b0) / (y1 - y0);

			double x = 0.0;
			double y = B;
			double z = 0.0;
			int r, g, b;
			bool tag = false;    // �Ƿ񱻲ü�����
			// ���1�����ղ��͵����ӣ�
			if (y0 < B && y1 >= B) {
				x = k * (B - y1) + x1;
				r = kr * (B - y1) + r1;
				g = kg * (B - y1) + g1;
				b = kb * (B - y1) + b1;
				// ע���Z R G B�Ĳ�ֵ����
				bottom.emplace_back(Point(x, y, z, r, g, b));
				bottom.emplace_back(p1);
			}
			// ���2
			else if (y0 >= B && y1 >= B) {
				bottom.emplace_back(p1);
			}
			// ���3
			else if (y0 >= B && y1 < B) {
				x = k * (B - y1) + x1;
				r = kr * (B - y1) + r1;
				g = kg * (B - y1) + g1;
				b = kb * (B - y1) + b1;
				bottom.emplace_back(Point(x, y, z, r, g, b));
			}
			// ���4�����ɼ����������κδ���
		}
		if (!bottom.empty())
			bottom.push_back(bottom[0]);
		plane.clear();
		plane = std::move(bottom);
	}
}


void PolygonCliper::setBoundary(double t, double b, double l, double r)
{
	T = t;
	B = b;
	L = l;
	R = r;
}
