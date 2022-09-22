#include "AABB.h"
#include "Movable.h"
#include "Mat.h"

#define PI 3.14159265

AABB::AABB(double tlx, double tly, double brx, double bry)
{
	TL(tlx, tly);
	BR(brx, bry);
}


AABB::AABB(Point tl, Point br)
{
	TL = tl;
	BR = br;

}

std::shared_ptr<Point> AABB::getCenter()
{
	std::shared_ptr<Point> Center = std::make_shared<Point>();
	Center->SetX((TL.GetX() + BR.GetX()) / 2);
	Center->SetY((TL.GetY() + BR.GetY()) / 2);
	return Center;
}

int AABB::GetLen()
{
	return static_cast<int>(BR.GetX() - TL.GetX());
}


int AABB::GetWid()
{
	return static_cast<int>(BR.GetY() - TL.GetY());
}

Point AABB::GetTL()
{
	return TL;
}

Point AABB::GetBR()
{
	return BR;
}

bool AABB::operator==(const AABB& range)
{
	if (!(BR.GetX() < range.TL.GetX() - 1 || range.BR.GetX() + 1 < TL.GetX()) &&
		!(BR.GetY() < range.TL.GetY() - 1 || range.BR.GetY() + 1 < TL.GetY()))
	{
		return true;
	}
	return false;
}

bool AABB::operator<(AABB& range)
{
	return range.GetTL().GetX() > GetTL().GetX();
}

bool AABB::cmpPtN(AABB* range, AABB* secRange)
{
	return (range->GetTL().GetX() < secRange->GetTL().GetX());
}

int AABB::operator-=(AABB& range)
{
	if ((range.GetTL().GetX() - BR.GetX() == 1 || TL.GetX() - range.GetBR().GetX() == 1) && (TL.GetY() <= range.BR.GetY() && BR.GetY() >= range.TL.GetY()))
	{
		if ((range.GetTL().GetY() - BR.GetY() == 1 || TL.GetY() - range.GetBR().GetY() == 1) && (TL.GetX() <= range.BR.GetX() && BR.GetX() >= range.TL.GetX()))
			return 3;
		return 1;
	}
	if ((range.GetTL().GetY() - BR.GetY() == 1 || TL.GetY() - range.GetBR().GetY() == 1) && (TL.GetX() <= range.BR.GetX() && BR.GetX() >= range.TL.GetX()))
	{
		return 2;
	}
	if (*getAABB() == range)
	{
		return 4;
	}
	return false;
}

bool AABB::isContaining(Point pnt) const
{
	if ((pnt.GetX() >= TL.GetX() && pnt.GetX() <= BR.GetX()) &&
		(pnt.GetY() >= TL.GetY() && pnt.GetY() <= BR.GetY()))
	{
		return true;
	}
	return false;
}

void AABB::operator=(AABB& origin)
{
	TL = origin.TL;
	BR = origin.BR;
}

void AABB::operator()(double top_left_x, double top_left_y, double bottom_right_x, double bottom_right_y)
{
	TL(top_left_x, top_left_y);
	BR(bottom_right_x, bottom_right_y);
}

void AABB::operator()(Point top_left, Point bottom_right)
{
	TL(top_left.GetX(), top_left.GetY());
	BR(bottom_right.GetX(), bottom_right.GetY());
}

void AABB::operator*=(double f)
{
	Point ttl = TL;
	TL.SetX(TL.GetX() - ((BR.GetX() - TL.GetX()) / (f / 2)));
	TL.SetY(TL.GetY() - ((BR.GetY() - TL.GetY()) / (f / 2)));
	BR.SetX(BR.GetX() + ((BR.GetX() - ttl.GetX()) / (f / 2)));
	BR.SetY(BR.GetY() + ((BR.GetY() - ttl.GetY()) / (f / 2)));
}


void AABB::SetTL(double x, double y)
{
	TL.SetX(x);
	TL.SetY(y);
}
void AABB::SetBR(double x, double y)
{
	BR.SetX(x);
	BR.SetY(y);
}

AABB* AABB::getAABB()
{
	return this;
}

short AABB::WIRTTO(AABB t) //where in relation to this object
{
	double tl = t.GetLen() / 2;
	double tw = t.GetWid() / 2;
	double deg = 0;
	if (pow(tl, 2) >= pow(tw, 2)) {
		deg = 90 - (atan(tw / tl) * 180.0 / PI);

		tl = getCenter()->GetX() - t.getCenter()->GetX();
		tw = getCenter()->GetY() - t.getCenter()->GetY();

		if (tl >= 0 && tw <= 0)
		{
			double tm = t.getCenter()->GetY() - GetBR().GetY();
			double jm = GetTL().GetX() - t.getCenter()->GetX();
			if (jm <= 0)
				return top;
			if (tm <= 0)
				return right;
			double ndeg = 90 - (atan(tm / jm) * 180.0 / PI);

			if (abs(ndeg) <= deg)
				return top;
			else
				return right;
		}
		else if (tl >= 0 && tw >= 0)
		{
			double tm = GetTL().GetY() - t.getCenter()->GetY();
			double jm = GetTL().GetX() - t.getCenter()->GetX();
			if (jm <= 0)
				return bottom;
			if (tm <= 0)
				return right;
			double ndeg = 90 - (atan(tm / jm) * 180.0 / PI);

			if (abs(ndeg) <= deg)
				return bottom;
			else
				return right;
		}
		else if (tl <= 0 && tw <= 0)
		{
			double tm = t.getCenter()->GetY() - GetBR().GetY();
			double jm = t.getCenter()->GetX() - GetBR().GetX();
			if (jm <= 0)
				return top;
			if (tm <= 0)
				return left;
			double ndeg = 90 - (atan(tm / jm) * 180.0 / PI);
			if (abs(ndeg) <= deg)
				return top;
			else
				return left;
		}
		else
		{
			double tm = GetTL().GetY() - t.getCenter()->GetY();
			double jm = t.getCenter()->GetX() - GetBR().GetX();
			if (jm <= 0)
				return bottom;
			if (tm <= 0)
				return left;
			double ndeg = 90 - (atan(tm / jm) * 180.0 / PI);

			if (abs(ndeg) <= deg)
				return bottom;
			else
				return left;
		}
	}

	else if (pow(tl, 2) < pow(tw, 2))
	{
		deg = atan(tw / tl) * 180.0 / PI;
		tl = getCenter()->GetX() - t.getCenter()->GetX();
		tw = getCenter()->GetY() - t.getCenter()->GetY();
		if (tl >= 0 && tw <= 0)
		{
			double tm = t.getCenter()->GetY() - GetBR().GetY();
			double jm = GetTL().GetX() - t.getCenter()->GetX();
			if (jm <= 0)
				return top;
			if (tm <= 0)
				return right;
			double ndeg = (atan(tm / jm) * 180.0 / PI);

			if (abs(ndeg) <= deg)
				return right;
			else
				return top;
		}
		else if (tl >= 0 && tw >= 0)
		{
			double tm = GetTL().GetY() - t.getCenter()->GetY();
			double jm = GetTL().GetX() - t.getCenter()->GetX();
			if (jm <= 0)
				return bottom;
			if (tm <= 0)
				return right;
			double ndeg = (atan(tm / jm) * 180.0 / PI);

			if (abs(ndeg) <= deg)
				return right;
			else
				return bottom;
		}
		else if (tl <= 0 && tw <= 0)
		{
			double tm = t.getCenter()->GetY() - GetBR().GetY();
			double jm = t.getCenter()->GetX() - GetBR().GetX();
			if (jm <= 0)
				return top;
			if (tm <= 0)
				return left;
			double ndeg = (atan(tm / jm) * 180.0 / PI);
			if (abs(ndeg) <= deg)
				return left;
			else
				return top;
		}
		else
		{
			double tm = GetTL().GetY() - t.getCenter()->GetY();
			double jm = t.getCenter()->GetX() - GetBR().GetX();
			if (jm <= 0)
				return bottom;
			if (tm <= 0)
				return left;
			double ndeg = (atan(tm / jm) * 180.0 / PI);

			if (abs(ndeg) <= deg)
				return left;
			else
				return bottom;
		}
	}
	else
	{
		return top;
	}
}


double AABB::Overlap(AABB t, short direction)
{
	double overlap = 0;
	double a = GetWid() / 2;
	double b = t.GetWid() / 2;
	double c = t.getCenter()->GetY();
	double d = getCenter()->GetY();
	switch (direction)
	{
	case top:
		overlap = (GetWid() / 2) + (t.GetWid() / 2) - (t.getCenter()->GetY() - getCenter()->GetY());
		if (overlap > 0)
			return overlap;
		return 0;
	case bottom:
		overlap = (GetWid() / 2) + (t.GetWid() / 2) - (getCenter()->GetY() - t.getCenter()->GetY());
		if (overlap > 0)
			return overlap;
		return 0;
	case left:
		overlap = (GetLen() / 2) + (t.GetLen() / 2) - (t.getCenter()->GetX() - getCenter()->GetX());
		if (overlap > 0)
			return overlap;
		return 0;
	case right:
		overlap = (GetLen() / 2) + (t.GetLen() / 2) - (getCenter()->GetX() - t.getCenter()->GetX());
		if (overlap > 0)
			return overlap;
		return 0;
	default:
		return 0;
	}
}