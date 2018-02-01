#include "Ant.h"

Ant::Ant(Vec2 pos)
	:
	pos(pos)
{
}

void Ant::AddPath(Vec2 & vec)
{
	path.push_front(vec);
}

void Ant::Update(float dt)
{
	if (!path.empty())
	{
		if (pos == path.front())
		{
			path.pop_front();
		}
		else
		{
			MoveTowards(path.front());
		}
	}
}

void Ant::MoveTowards(const Vec2 & dest)
{
	const Vec2 destVec = dest.GetNormalized();

	pos += destVec * speed;
}

void Ant::Draw(Graphics & gfx) const
{
	gfx.DrawCircle(pos.x, pos.y, radius, Colors::White);
}

Vec2 Ant::GetPos()
{
	return pos;
}

