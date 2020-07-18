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
	// todo: 実装して下さい
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
	// todo: 実装して下さい
	return vector3();
}

quaternion quaternion::operator*(const quaternion& rhs) const
{
	// todo: 実装して下さい
	return quaternion();
}

quaternion quaternion::operator+(const quaternion& rhs) const
{
	return quaternion(x_ + rhs.x_, y_ + rhs.y_, z_ + rhs.z_, w_ + rhs.w_);
}


// 単位元にする
quaternion &quaternion::identity()
{
	// todo: 実装して下さい
	return *this;
}

// 正規化する
quaternion &quaternion::normalize()
{
	float l;
	l = sqrt(x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_);
	quaternion::x_ = x_/l;
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
	// todo: 実装して下さい
	return quaternion();
}

// 逆元を返す
quaternion quaternion::inverse() const
{
	// todo: 実装して下さい
	return quaternion();
}

// 球面線形補間
quaternion quaternion::slerp(const quaternion& q0, const quaternion& q1, float t)
{
	// todo: 実装して下さい
	return quaternion();
}

