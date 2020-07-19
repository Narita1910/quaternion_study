#include "pch.h"
#include <cmath>
#include "../include/libquat.h"




// コンストラクタ
quaternion::quaternion()
{
	quaternion::x_ = 0;
	quaternion::y_ = 0;
	quaternion::z_ = 0;
	quaternion::w_ = 1;
}

quaternion::quaternion(float x, float y, float z, float w)
{
	quaternion::x_ = x;
	quaternion::y_ = y;
	quaternion::z_ = z;
	quaternion::w_ = w;
}

quaternion::quaternion(const vector3 &v, float arg)
{
	quaternion::x_ = v.x();
	quaternion::y_ = v.y();
	quaternion::z_ = v.z();
	quaternion::w_ = arg;
}

// デストラクタ
quaternion::~quaternion()
{
}

quaternion quaternion::operator*(float f) const
{
	return quaternion(x_ * f, y_ * f, z_ * f, w_ * f);
}

quaternion quaternion::operator/(float f) const
{
	return quaternion(x_ / f, y_ / f, z_ / f, w_ / f);
}

vector3 quaternion::operator*(const vector3& v) const
{
	return vector3(x_ * v.x(), y_ * v.y(), z_ * v.z());
}

quaternion quaternion::operator*(const quaternion& rhs) const
{
	
	return quaternion(x_ * rhs.x_, y_ * rhs.y_, z_ * rhs.z_, w_ * rhs.w_);
}

quaternion quaternion::operator+(const quaternion& rhs) const
{
	return quaternion(x_ + rhs.x_, y_ + rhs.y_, z_ + rhs.z_, w_ + rhs.w_);
}


// 単位元にする
quaternion &quaternion::identity()
{
	
	quaternion::x_ = 0;
	quaternion::y_ = 0;
	quaternion::z_ = 0;
	quaternion::w_ = 1;
	return *this;
}

// 正規化する
quaternion &quaternion::normalize()
{
	float l;
	l = sqrt(x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_);
	quaternion::x_ = x_ / l;
	quaternion::y_ = y_ / l;
	quaternion::z_ = z_ / l;
	quaternion::w_ = w_ / l;
	return *this;
}

// 大きさの2乗
float quaternion::length_sq() const
{
	return x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_;
}

// 共役を返す
quaternion quaternion::conjugate() const
{
	return quaternion(-x_, -y_, -z_, w_);
}

// 逆元を返す
quaternion quaternion::inverse() const
{
	quaternion c = conjugate();
	float leng = length_sq();
	return quaternion(c.x_/leng, c.y_ / leng, c.z_ / leng, c.w_ / leng);
}

// 球面線形補間
quaternion quaternion::slerp(const quaternion& q0, const quaternion& q1, float t)
{
	quaternion q;
	float qr = q0.x_ * q1.x_ + q0.y_ * q1.y_ + q0.z_ * q1.z_+ q0.w_ * q1.w_ ;
	float i = 1.0f - qr * qr;

	if (i == 0.0f) {
		q.x_ = q0.x_;
		q.y_ = q0.y_;
		q.z_ = q0.z_;
		q.w_ = q0.w_;
		return quaternion(q.x_,q.y_,q.z_,q.w_);
	}
	else {
		float sp = sqrt(i);
		float ph = acos(qr);
		float pt = ph * t;
		float t1 = sin(pt) / sp;
		float t0 = sin(ph - pt) / sp;

		q.x_ = q0.x_ * t0 + q1.x_ * t1;
		q.y_ = q0.y_ * t0 + q1.y_ * t1;
		q.z_ = q0.z_ * t0 + q1.z_ * t1;
		q.w_ = q0.w_ * t0 + q1.w_ * t1;
		return quaternion(q.x_, q.y_, q.z_, q.w_);
	}
}
