#include "stdafx.h"
#include "CppUnitTest.h"
#include "Button.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TowerDefenseTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			var button = new Button;
			var event = new sf::Event;
			button.resolveEvent(event);
			Assert.AreEqual(button.checkClick == false);

		}
	};
}