#include "Player.h"
#include "../Utils/InputMgr.h"
#include "../Utils/Utils.h"
#include <iostream>

/*==============================
		�÷��̾� ������
================================*/
Player::Player()
	:speed(START_SPEED), gravity(GRAVITY), isJump(false), isDash(false), isCatch(false)
	, isFalling(true)
{	
}

/*==============================
	    �÷��̾� �ʱ�ȭ
================================*/
void Player::Init()
{
	sprite.setPosition(400,1000);
	sprite.setScale(4.f, 4.f);
	sprite.setOrigin(50, 0);

	texture.loadFromFile("graphics/player_idle A_B_C.png");
	animation.SetTarget(&sprite);
	AnimationClip IdleClip;

	IdleClip.id = "Idle";
	IdleClip.fps = 10;
	IdleClip.loopType = AnimationLoopTypes::Loop;
	IdleClip.frames.push_back(AnimationFrame(texture, IntRect(0, 0, 32, 32), Vector2f(16, 16)));
	IdleClip.frames.push_back(AnimationFrame(texture, IntRect(32, 0, 32, 32), Vector2f(16, 16)));
	IdleClip.frames.push_back(AnimationFrame(texture, IntRect(64, 0, 32, 32), Vector2f(16, 16)));
	IdleClip.frames.push_back(AnimationFrame(texture, IntRect(96, 0, 32, 32), Vector2f(16, 16)));
	IdleClip.frames.push_back(AnimationFrame(texture, IntRect(128, 0, 32, 32), Vector2f(16, 16)));
	IdleClip.frames.push_back(AnimationFrame(texture, IntRect(160, 0, 32, 32), Vector2f(16, 16)));
	IdleClip.frames.push_back(AnimationFrame(texture, IntRect(192, 0, 32, 32), Vector2f(16, 16)));
	IdleClip.frames.push_back(AnimationFrame(texture, IntRect(224, 0, 32, 32), Vector2f(16, 16)));
	IdleClip.frames.push_back(AnimationFrame(texture, IntRect(0, 32, 32, 32), Vector2f(16, 16)));
	animation.AddClip(IdleClip);
	IdleClip.frames.clear();

	texture.loadFromFile("graphics/player_climb_dangling_walk.png");

	animation.SetTarget(&sprite);
	AnimationClip clip;

	clip.id = "Idle";
	clip.fps = 10;
	clip.loopType = AnimationLoopTypes::Loop;
	clip.frames.push_back(AnimationFrame(texture, IntRect(0, 0, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(32, 0, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(64, 0, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(96, 0, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(128, 0, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(160, 0, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(192, 0, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(224, 0, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(0, 32, 32, 32), Vector2f(16, 16)));
	animation.AddClip(clip);
	clip.frames.clear();

	clip.id = "Walk";
	clip.fps = 10;
	clip.loopType = AnimationLoopTypes::Loop;
	
	clip.frames.push_back(AnimationFrame(texture, IntRect(32, 96, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(64, 96, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(96, 96, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(128, 96, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(160, 96, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(192, 96, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(224, 96, 32, 32), Vector2f(16, 16)));

	clip.frames.push_back(AnimationFrame(texture, IntRect(0, 128, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(32, 128, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(64, 128, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(96, 128, 32, 32), Vector2f(16, 16)));
	clip.frames.push_back(AnimationFrame(texture, IntRect(128, 128, 32, 32), Vector2f(16, 16)));
	animation.AddClip(clip);
	clip.frames.clear();

	texture.loadFromFile("graphics/player_JumpCarry_JumpFast_JumpSlow_sitDown.png");

	animation.SetTarget(&sprite);
	AnimationClip clipJump;

	clipJump.id = "Jump";
	clipJump.fps = 10;
	clipJump.loopType = AnimationLoopTypes::Single;

	clipJump.frames.push_back(AnimationFrame(texture, IntRect(128, 0, 32, 32), Vector2f(16, 16)));
	clipJump.frames.push_back(AnimationFrame(texture, IntRect(160, 0, 32, 32), Vector2f(16, 16)));
	clipJump.frames.push_back(AnimationFrame(texture, IntRect(192, 0, 32, 32), Vector2f(16, 16)));
	clipJump.frames.push_back(AnimationFrame(texture, IntRect(224, 0, 32, 32), Vector2f(16, 16)));
	
	animation.AddClip(clipJump);
	clipJump.frames.clear();

	animation.Play("Idle");
}

void Player::Spawn(IntRect arena, Vector2i res)
{
	this->arena = arena;
	resolution = res;

	position.x = arena.width * 0.5;
	position.y = arena.height * 0.5;
	sprite.setPosition(position.x, position.y);

	
}
/*========================================
	Ű �Է¿� ���� �÷��̾��� �ִϸ��̼� 
==========================================*/
void Player::UpdateInput()
{
	if (InputMgr::GetKeyDown(Keyboard::Right)) //������ �̵�
	{
		sprite.setScale(4.f, 4.f);
		animation.Play("Walk");		
	}
	if (InputMgr::GetKeyDown(Keyboard::Left)) //���� �̵�
	{
		sprite.setScale(-4.f, 4.f);
		animation.Play("Walk");		
	}
	if (InputMgr::GetKeyUp(Keyboard::Right))
	{
		sprite.setScale(4.f, 4.f);
		animation.Play("Idle");
		animation.PlayQueue("Idle");
	}
	if (InputMgr::GetKeyUp(Keyboard::Left))
	{
		sprite.setScale(-4.f, 4.f);
		animation.Play("Idle");
		animation.PlayQueue("Idle");
	}
	if (InputMgr::GetKeyDown(Keyboard::C)) //����
	{
		isJump = true;
		sprite.setScale(4.f, 4.f);
		animation.Play("Jump");
		isJump = false;
		animation.PlayQueue("Idle");
	}
	if (InputMgr::GetKeyDown(Keyboard::X)) //�뽬
	{
		sprite.setScale(4.f, 4.f);
	}
	if (InputMgr::GetKeyDown(Keyboard::Z)) // �����
	{
		sprite.setScale(4.f, 4.f);
	}

}
/*============================================
	Ű �Է¿� ���� �÷��̾��� �׼� ������Ʈ
==============================================*/
void Player::Update(float dt, std::vector<Wall*> walls)
{
	UpdateInput();
	if (isFalling == true)
	{
		gravityV += gravity * dt;
		position.y += gravityV * dt;
	}
	/*float h = InputMgr::GetAxis(Axis::Horizontal);

	if (h > 0)
	{
		animation.Play("Walk");
		animation.PlayQueue("Idle");
	}
	if (h < 0)
	{
		sprite.setScale(-1.f, 1.f);
		animation.Play("Walk");
		animation.PlayQueue("Idle");
	}
	// ����
	if (InputMgr::GetKeyDown(Keyboard::C))
	{
		isJump = true;
		animation.Play("Jump");
		animation.PlayQueue("Idle");

		position.y += 1;

	}*/
	// �¿� �̵�
	if (InputMgr::GetKey(Keyboard::Right))
	{
		position.x += dt * speed;
	}
	if (InputMgr::GetKey(Keyboard::Left))
	{
		position.x -= dt * speed;
	}
	// ���� �̵�
	if (InputMgr::GetKeyDown(Keyboard::C))
	{
		if (position.y < 12.f)
		{
			!isFalling;
			position.y -= dt * speed * 3.f;
		}
		else
		{
			isFalling;
		}
	}
	if (InputMgr::GetKey(Keyboard::C))
	{
		if (position.y < 24.f)
		{
			!isFalling;
			position.y -= dt * speed * 3.f;
		}
		else
		{
			!isFalling;
		}
	}
	/*
	//�뽬
	if (InputMgr::GetKeyDown(Keyboard::X)||InputMgr::GetKey(Keyboard::X))
	{

	}
	// �����
	if (InputMgr::GetKeyDown(Keyboard::Z))
	{

	}*/
	/*Vector2f dir(h, v);
	float length = sqrt(dir.x * dir.x + dir.y * dir.y);
	if (length > 0)
	{
		dir /= length;
	}	
	position += dir * speed * dt;*/

	//�浹 ó��
	for (auto v : walls)
	{
		if (sprite.getGlobalBounds().intersects(v->GetWallRect()))
		{
			Pivots pivot = Utils::CollisionDir(v->GetWallRect(), sprite.getGlobalBounds());

			switch (pivot)
			{
			case Pivots::LC:
				position.x += (v->GetWallRect().left + v->GetWallRect().width) - (sprite.getGlobalBounds().left);
				break;

			case Pivots::RC:
				position.x -= (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width) - (v->GetWallRect().left);
				break;

			case Pivots::CT:
				position.y += (v->GetWallRect().top + v->GetWallRect().height) - (sprite.getGlobalBounds().top);
				break;

			case Pivots::CB:
				position.y -= (sprite.getGlobalBounds().top + sprite.getGlobalBounds().height) - (v->GetWallRect().top);
				break;

			defalut:
				break;
			}
			sprite.setPosition(position);
		}
	}
	sprite.setPosition(position);
	animation.Update(dt);
}

FloatRect Player::GetGobalBound() const
{
	return sprite.getGlobalBounds();
}

Vector2f Player::GetPosition() const
{
	return position;
}

Sprite Player::GetSprite() const
{
	return sprite;
}

/*==============================
		�÷��̾� �׸���
================================*/
void Player::Draw(RenderWindow &window)
{
	window.draw(sprite);
}
/*===============================
�� �� �� : �� �� ȭ
�� �� �� �� : �÷��̾� ���� ����
�� �� �� : 2022 - 05 - 04
�� �� �� : 2022 - 05 - 05
=================================*/