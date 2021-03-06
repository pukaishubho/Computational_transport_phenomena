#include "Engy5310P1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
Engy5310P1App::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

Engy5310P1App::Engy5310P1App(InputParameters parameters) : MooseApp(parameters)
{
  Engy5310P1App::registerAll(_factory, _action_factory, _syntax);
}

Engy5310P1App::~Engy5310P1App() {}

void
Engy5310P1App::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"Engy5310P1App"});
  Registry::registerActionsTo(af, {"Engy5310P1App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
Engy5310P1App::registerApps()
{
  registerApp(Engy5310P1App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
Engy5310P1App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Engy5310P1App::registerAll(f, af, s);
}
extern "C" void
Engy5310P1App__registerApps()
{
  Engy5310P1App::registerApps();
}
