#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <memory>
#include <string>
#include <vector>

#include "chatgui.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

/**
 * ChatLogic class
 * 
 * Manages the dialogs that appear within the ChatBotPanelDialog that
 * is used in the chatgui module. It is implementing the messaging system
 * between the user and the chatbot.
 */
class ChatLogic {
private:
  // data handles (owned)
  std::vector<std::unique_ptr<GraphNode>> _nodes;

  // data handles (not owned)
  GraphNode *_currentNode;
  ChatBot *_chatBot;
  ChatBotPanelDialog *_panelDialog;

  // proprietary type definitions
  typedef std::vector<std::pair<std::string, std::string>> tokenlist;

  // proprietary functions
  template <typename T>
  void AddAllTokensToElement(std::string tokenID, tokenlist &tokens,
                             T &element);

public:
  // constructor / destructor
  ChatLogic();
  ~ChatLogic();

  // getter / setter
  void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
  void SetChatbotHandle(ChatBot *chatbot);

  // proprietary functions
  void LoadAnswerGraphFromFile(std::string filename);
  void SendMessageToChatbot(std::string message);
  void SendMessageToUser(std::string message);
  wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */