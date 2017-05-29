
#ifndef _STATES_
#define _STATES_

class TM;

/*============================================================================
==============================================================================
==================================  States  ==================================
==============================================================================
==============================================================================*/
// base class for State
class State {
public:
  virtual void enterState() = 0;
  virtual void executeState(TM *tm) = 0;
  virtual void exitState() = 0;
};

/*=============================================================================
================================  First State  ================================
==============================================================================*/
class FirstState : public State {
private:
  // constructor
  FirstState() {}
  // copy constructor
  FirstState(const FirstState &);
  // assignment
  FirstState &operator=(const FirstState &);

public:
  // singleton
  static FirstState *Instance();
  virtual void enterState();
  virtual void executeState(TM *tm);
  virtual void exitState();
};

/*=============================================================================
=================================  Find A  ====================================
==============================================================================*/
class FindA : public State {
private:
  // constructor
  FindA() {}
  // copy constructor
  FindA(const FindA &);
  // assignment
  FindA &operator=(const FindA &);

public:
  // singleton
  static FindA *Instance();
  virtual void enterState();
  virtual void executeState(TM *tm);
  virtual void exitState();
};

/*=============================================================================
=================================  Find B  ====================================
==============================================================================*/
class FindB : public State {
private:
  // constructor
  FindB() {}
  // copy constructor
  FindB(const FindB &);
  // assignment
  FindB &operator=(const FindB &);

public:
  // singleton
  static FindB *Instance();
  virtual void enterState();
  virtual void executeState(TM *tm);
  virtual void exitState();
};

/*=============================================================================
==================================  Find C  ===================================
==============================================================================*/
class FindC : public State {
private:
  // constructor
  FindC() {}
  // copy constructor
  FindC(const FindC &);
  // assignment
  FindC &operator=(const FindC &);

public:
  // singleton
  static FindC *Instance();
  virtual void enterState();
  virtual void executeState(TM *tm);
  virtual void exitState();
};

/*=============================================================================
===================================  Accept  ==================================
==============================================================================*/
class Accept : public State {
private:
  // constructor
  Accept() {}
  // copy constructor
  Accept(const Accept &);
  // assignment
  Accept &operator=(const Accept &);

public:
  // singleton
  static Accept *Instance();
  virtual void enterState();
  virtual void executeState(TM *tm);
  virtual void exitState();
};

/*=============================================================================
===================================  Reject  ==================================
==============================================================================*/
class Reject : public State {
private:
  // constructor
  Reject() {}
  // copy constructor
  Reject(const Reject &);
  // assignment
  Reject &operator=(const Reject &);

public:
  // singleton
  static Reject *Instance();
  virtual void enterState();
  virtual void executeState(TM *tm);
  virtual void exitState();
};

/*=============================================================================
================================  EvaluateTape  ===============================
==============================================================================*/
class EvaluateTape : public State {
private:
  // constructor
  EvaluateTape() {}
  // copy constructor
  EvaluateTape(const EvaluateTape &);
  // assignment
  EvaluateTape &operator=(const EvaluateTape &);

public:
  // singleton
  static EvaluateTape *Instance();
  virtual void enterState();
  virtual void executeState(TM *tm);
  virtual void exitState();
};
#endif
