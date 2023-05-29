# Necessary Libraries
import nltk
from nltk.chat.util import Chat, reflections

# Define the reflections dictionary
# reflections = {
#     "i am": "you are",
#     "i was": "you were",
#     "i": "you",
#     "i'm": "you are",
#     "i'd": "you would",
#     "i've": "you have",
#     "i'll": "you will",
#     "my": "your",
#     "you are": "I am",
#     "you were": "I was",
#     "you've": "I have",
#     "you'll": "I will",
#     "your": "my",
#     "yours": "mine",
#     "you": "me",
#     "me": "you"
# }

# Define the pairs of input/output messages
pairs = [
    [r"Hi(.*)|Hello(.*)|Hey there|Hola (.*)",
     ['Hello!', 'Hi there!', 'How can I help you?']],
    [r"I want to order (.*)|(.*)Order",
        ['Sure, what would you like to order?', 'What type of %1 would you like to order?']],
    [r'(.*)Menu(.*)', ['Please visit our website to see the menu.',
                       'The menu is available on our website.', 'Our speciality is Burger']],
    [r'How long does it take for the food to be delivered?|(.*)Delivery Time(.*)|(.*)Time to get delivered(.*)|(.*)Time(.*)', [
        'It usually takes 20 minutes for the food to be delivered.']],
    [r'What are the payment options?|(.*)Payment options(.*)|(.*)Payment(.*)', [
        'We accept all major credit cards and cash on delivery.UPI also available']],
    [r"Thank you|(.*)Thanks(.*)|Thanks alot",
     ['You\'re welcome!', 'Enjoy your meal!']],
    [r'Bye|Goodbye|Exit', ['Goodbye!', 'See you soon!']]
]

# Define a function to chat with the user


def chatbot():
    print("Hi! How can I assist you today?")
    chatbot = Chat(pairs, reflections)
    chatbot.converse()


# Call the chatbot function
chatbot()
