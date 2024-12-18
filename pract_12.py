class STORE:
    def __init__(self):
        # Initializing product list with sample data
        self.products = [
            {"code": 101, "name": "Milk", "price": 50},
            {"code": 102, "name": "Bread", "price": 30},
            {"code": 103, "name": "Butter", "price": 70},
            {"code": 104, "name": "Cheese", "price": 90},
        ]

    def display_menu(self):
        print("Available Products:")
        print("-------------------")
        for product in self.products:
            print(f"Code: {product['code']}, Name: {product['name']}, Price: {product['price']}")

    def generate_bill(self):
        total = 0
        print("\nEnter product code and quantity (Enter 0 to finish):")
        while True:
            code = int(input("Enter product code: "))
            if code == 0:
                break
            quantity = int(input("Enter quantity: "))
            # Find the product in the list
            for product in self.products:
                if product['code'] == code:
                    total += product['price'] * quantity
                    print(f"Added {product['name']} x {quantity} = {product['price'] * quantity}")
                    break
            else:
                print("Invalid product code.")
        print(f"\nTotal Bill: {total}")

# Main program
store = STORE()
store.display_menu()
store.generate_bill()