class CCreature{
	protected:
		int m_nLifeValue, m_nPower;
	public:
		virtual void Attack(CCreature* pCreature){}
		virtual void Hurted(int nPower){}
		virtual void FightBack(CCreature* pCreature){}
};

class CDragon: public CCreatrue{
	public:
		virtual void Attack(CCreature* pCreature);
		virtual void Hurted(int nPower);
		virtual void FightBack(CCreature* pCreature);
};  

void CDragon::Attack(CCreature *p){
	//表示攻击动作的代码	
	p->Hurted(m_nPower);//多态
	p->FightBack(this);//多态
}

void CDragon::Hurted(int nPower){
	//...表示受伤动作的代码
	m_nLifeValue -= nPower;
}

void CDragon::FightBack(CCreature *p){
	//..表示反击动作的代码
	p->Hurted(m_nPower/2);
}
