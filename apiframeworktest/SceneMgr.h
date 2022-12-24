#pragma once
class Scene;
class SceneMgr 
{
public:
	SINGLE(SceneMgr);
private:
	SceneMgr();
	~SceneMgr();
private:
	Scene* m_arrScene[(UINT)SCENE_TYPE::END]; // ¸ðµç ¾À ¸ñ·Ï
	Scene* m_pCurScene;						  // ÇöÀç ¾À
public:
	Scene* GetCurScene() { return m_pCurScene; }
	void ChangeScene(SCENE_TYPE _eNext);
private:
	friend class EventMgr;
public:
	void	 Init();
	void	 Update();
	void	 Render(HDC _dc);
};

