#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include <vector>
#include <forward_list>


class Ant 
{
public: 
	enum class Job
	{
		worker,
		fighter
	};
public:
	Ant(Vec2 pos);
	void AddPath(Vec2& vec);
	void Update(float dt);
	void MoveTowards(const Vec2& dest);
	void Draw(Graphics& gfx) const;
	Vec2 GetPos();
private:
	static constexpr int radius = 3;
	static constexpr int speed = 200;
	Vec2 pos;
	Job type = Job::worker;
	std::forward_list<Vec2> path;
};