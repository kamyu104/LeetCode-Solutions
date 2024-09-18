**Calculating Marketability with Simple Q Code in KDB+**

Given a table with the following four columns:

- `time`: Timestamp of the order
- `side`: `'Buy'` or `'Sell'` indicating the order side
- `orderPrice`: The price of the order
- `bestBid`: Best bid price at time `T`
- `bestAsk`: Best ask price at time `T`

You can calculate the marketability of each order using simple Q code.

---

**1. Sample Data Table**

Assuming your table is named `orders`, here's sample data:

```q
orders:([] 
  time:      (2023.10.01D12:00:00.000; 2023.10.01D12:00:01.000; 2023.10.01D12:00:02.000);
  side:      `Buy`Sell`Buy;
  orderPrice:200.00 199.98 200.03;
  bestBid:   199.98 199.98 199.98;
  bestAsk:   200.02 200.02 200.02
)
```

---

**2. Simple Q Code to Calculate Marketability**

**Method 1: Using a Function**

```q
// Define a function to check marketability
checkMarketability:{[side; orderPrice; bestBid; bestAsk]
  $[side=`Buy; 
      orderPrice >= bestAsk;       // Buy order is marketable if price ≥ best ask
    side=`Sell; 
      orderPrice <= bestBid;       // Sell order is marketable if price ≤ best bid
    0b                             // Otherwise, not marketable
  ]
}

// Apply the function to each row
orders: update marketable: checkMarketability[side; orderPrice; bestBid; bestAsk] from orders
```

**Method 2: Using Vectorized Operations**

```q
// Calculate marketability directly
orders: update marketable: ((side=`Buy) & (orderPrice >= bestAsk)) 
                         | ((side=`Sell) & (orderPrice <= bestBid)) 
                         from orders
```

---

**3. Explanation**

- **For Buy Orders:**
  - An order is **marketable** if `orderPrice ≥ bestAsk`.
- **For Sell Orders:**
  - An order is **marketable** if `orderPrice ≤ bestBid`.
- The `marketable` column is a boolean (`1b` for true, `0b` for false).

---

**4. Resulting Table**

After applying the code, the `orders` table will have an additional `marketable` column:

```
time                          side  orderPrice  bestBid  bestAsk  marketable
----------------------------------------------------------------------------
2023.10.01D12:00:00.000000000 Buy   200         199.98   200.02   0b
2023.10.01D12:00:01.000000000 Sell  199.98      199.98   200.02   1b
2023.10.01D12:00:02.000000000 Buy   200.03      199.98   200.02   1b
```

---

**5. Notes**

- **Efficiency:** Method 2 is more efficient as it uses vectorized operations.
- **Flexibility:** You can extend the logic to include additional conditions or parameters if needed.
- **Assumptions:** This code assumes that all necessary columns are present and that `side` contains only `'Buy'` or `'Sell'`.

---

**6. Conclusion**

Using the simple Q code provided, you can calculate the marketability of orders in your KDB+ table based on the order side and prices. This method is efficient and easily integrates into high-frequency trading systems where quick computations are essential.



computePriceDifference:{[t]
    // Calculate the midprice
    t[`midprice]:(t[`bid] + t[`ask]) % 2;

    // Calculate the price difference based on side
    t[`priceDifference]: (t[`side]="Buy") * (t[`price] - t[`midprice]) +
                         (t[`side]="Sell") * (t[`midprice] - t[`price]);

    // Add the marketable flag
    t[`marketable]: ((t[`side]="Buy") & (t[`price] >= t[`ask])) |
                    ((t[`side]="Sell") & (t[`price] <= t[`bid]));

    t
}




To address your problem, we'll need to analyze the relationship between the predicted top city, its associated value in `mycol1`, whether `mycol2` is non-NaN, and the hit ratio. Below are three statistical methods to quantify this relationship, along with Python implementations. We'll proceed step by step.

### **Step 1: Data Preparation**

1. **Create `mycol1` Map:**
   - Combine `mycol1a` (list of cities) and `mycol1b` (list of values) into a dictionary for each row.
   - Example:

     ```python
     df['mycol1'] = df.apply(lambda x: dict(zip(x['mycol1a'], x['mycol1b'])), axis=1)
     ```

2. **Determine the Top City and Its Value:**
   - For each row, find the city with the highest value in `mycol1`.
   - Example:

     ```python
     df['top_city'] = df['mycol1'].apply(lambda x: max(x, key=x.get))
     df['top_city_value'] = df['mycol1'].apply(lambda x: x[df['top_city']])
     ```

3. **Create Indicator for `mycol2` Non-NaN Values:**
   - Create a binary column indicating whether `mycol2` is non-NaN.

     ```python
     df['mycol2_non_nan'] = df['mycol2'].notna().astype(int)
     ```

4. **Calculate Overall Hit Ratio:**
   - Hit Ratio = Number of non-NaN `mycol2` entries divided by total number of rows.

     ```python
     total_rows = len(df)
     non_nan_rows = df['mycol2_non_nan'].sum()
     hit_ratio = non_nan_rows / total_rows
     ```

5. **Calculate Hit Ratio for Each Top City:**
   - Group by `top_city` and calculate the hit ratio.

     ```python
     hit_ratio_by_city = df.groupby('top_city')['mycol2_non_nan'].mean()
     ```

### **Step 2: Statistical Methods**

#### **Method 1: Logistic Regression**

- **Purpose:** Model the probability of `mycol2` being non-NaN based on the top city's value.
- **Implementation:**

  ```python
  import statsmodels.api as sm

  # Independent variable (add constant for intercept)
  X = sm.add_constant(df['top_city_value'])
  # Dependent variable
  y = df['mycol2_non_nan']

  # Logistic Regression Model
  model = sm.Logit(y, X)
  result = model.fit()

  print(result.summary())
  ```

- **Interpretation:**
  - The coefficients will tell you how the top city value influences the likelihood of `mycol2` being non-NaN.
  - A significant positive coefficient implies that higher top city values increase the probability of `mycol2` being non-NaN.

#### **Method 2: Chi-Square Test of Independence**

- **Purpose:** Test if there's a significant association between the top city and whether `mycol2` is non-NaN.
- **Implementation:**

  ```python
  import pandas as pd
  from scipy.stats import chi2_contingency

  # Create contingency table
  contingency_table = pd.crosstab(df['top_city'], df['mycol2_non_nan'])

  # Perform Chi-Square Test
  chi2, p, dof, expected = chi2_contingency(contingency_table)

  print(f"Chi-Square Statistic: {chi2}")
  print(f"P-value: {p}")
  ```

- **Interpretation:**
  - A low p-value (typically < 0.05) indicates a significant association between the top city and `mycol2` being non-NaN.
  - This suggests that the top city category influences the occurrence of non-NaN values in `mycol2`.

#### **Method 3: Point-Biserial Correlation**

- **Purpose:** Measure the correlation between a binary variable (`mycol2_non_nan`) and a continuous variable (`top_city_value`).
- **Implementation:**

  ```python
  from scipy.stats import pointbiserialr

  correlation, p_value = pointbiserialr(df['mycol2_non_nan'], df['top_city_value'])

  print(f"Point-Biserial Correlation: {correlation}")
  print(f"P-value: {p_value}")
  ```

- **Interpretation:**
  - The correlation coefficient ranges from -1 to 1.
  - A positive correlation suggests that higher top city values are associated with `mycol2` being non-NaN.
  - The p-value indicates the significance of the correlation.

### **Step 3: Additional Quantifiable Relationships**

1. **Hit Ratio Analysis by Top City:**

   - **Purpose:** Determine if certain top cities have higher hit ratios.
   - **Implementation:**

     ```python
     import matplotlib.pyplot as plt

     # Bar plot of hit ratios by top city
     hit_ratio_by_city.plot(kind='bar')
     plt.ylabel('Hit Ratio')
     plt.title('Hit Ratio by Top City')
     plt.show()
     ```

   - **Interpretation:**
     - Visualize which cities contribute more to the hit ratio.
     - Identify cities with significantly higher or lower hit ratios.

2. **ANOVA Test:**

   - **Purpose:** Compare the means of `top_city_value` across groups defined by `mycol2` being NaN or non-NaN.
   - **Implementation:**

     ```python
     from scipy.stats import f_oneway

     # Separate the data into two groups
     group_non_nan = df[df['mycol2_non_nan'] == 1]['top_city_value']
     group_nan = df[df['mycol2_non_nan'] == 0]['top_city_value']

     # Perform ANOVA
     f_stat, p_value = f_oneway(group_non_nan, group_nan)

     print(f"F-Statistic: {f_stat}")
     print(f"P-value: {p_value}")
     ```

   - **Interpretation:**
     - A significant p-value indicates that the means of `top_city_value` differ between the two groups.

3. **Decision Tree Analysis:**

   - **Purpose:** Identify patterns and thresholds in `top_city_value` that predict `mycol2` being non-NaN.
   - **Implementation:**

     ```python
     from sklearn.tree import DecisionTreeClassifier
     from sklearn import tree

     X = df[['top_city_value']]
     y = df['mycol2_non_nan']

     clf = DecisionTreeClassifier()
     clf = clf.fit(X, y)

     tree.plot_tree(clf)
     plt.show()
     ```

   - **Interpretation:**
     - The decision tree can reveal value thresholds of `top_city_value` that significantly impact the probability of `mycol2` being non-NaN.

### **Conclusion**

By applying these statistical methods, you can quantitatively assess the relationships in your data:

- **Logistic Regression** helps model the probability of an event occurring based on predictor variables.
- **Chi-Square Test** assesses the association between two categorical variables.
- **Point-Biserial Correlation** measures the strength and direction of the association between a continuous and a binary variable.
- **Additional methods** like ANOVA and Decision Trees offer further insights into your data's structure and relationships.

### **References**

- **Pandas Documentation:** [https://pandas.pydata.org/docs/](https://pandas.pydata.org/docs/)
- **Statsmodels Documentation:** [https://www.statsmodels.org/stable/index.html](https://www.statsmodels.org/stable/index.html)
- **SciPy Statistical Functions:** [https://docs.scipy.org/doc/scipy/reference/stats.html](https://docs.scipy.org/doc/scipy/reference/stats.html)
- **Scikit-Learn Documentation:** [https://scikit-learn.org/stable/](https://scikit-learn.org/stable/)





Absolutely, we can enhance the analysis by conditioning on the actual city and examining the rank of the predicted city within the top predictions. Incorporating the known city sequence (`seq = ['nyc', 'miami', 'chicago', 'london', 'none']`) allows us to consider the hierarchical importance of each city and assess the model's performance accordingly.

Below, I'll provide detailed methods and ideas to quantify and analyze these relationships, along with Python implementations.

---

### **Step 1: Data Preparation**

First, let's prepare the data to facilitate the analysis.

1. **Create `mycol1` Map:**

   ```python
   df['mycol1'] = df.apply(lambda x: dict(zip(x['mycol1a'], x['mycol1b'])), axis=1)
   ```

2. **Sort Predicted Cities by Value:**

   - For each row, sort the predicted cities in descending order of their values to obtain a ranked list.

     ```python
     df['sorted_cities'] = df['mycol1'].apply(lambda x: sorted(x.items(), key=lambda item: item[1], reverse=True))
     ```

3. **Extract Top N Predicted Cities:**

   - Extract the top N predicted cities (e.g., top 3).

     ```python
     df['top_cities'] = df['sorted_cities'].apply(lambda x: [city for city, value in x])
     df['top3_cities'] = df['top_cities'].apply(lambda x: x[:3])
     ```

4. **Determine Actual City:**

   - Assuming you have a column `actual_city` indicating the correct city.

5. **Calculate Rank of Actual City in Predictions:**

   - For each row, find the rank of the actual city in the predicted list.

     ```python
     def get_rank(predictions, actual):
         try:
             return predictions.index(actual) + 1  # Ranks start at 1
         except ValueError:
             return None  # Actual city not in predictions

     df['actual_city_rank'] = df.apply(lambda x: get_rank(x['top_cities'], x['actual_city']), axis=1)
     ```

---

### **Step 2: Analysis by City (Conditioning on the Actual City)**

#### **1. Top-K Accuracy per City**

- **Purpose:** Determine how often the model predicts the actual city within the top K predictions for each city.

- **Implementation:**

  ```python
  # Function to calculate top-k accuracy
  def top_k_accuracy(group, k):
      total = len(group)
      correct = group['actual_city_rank'].apply(lambda x: x is not None and x <= k).sum()
      return correct / total if total > 0 else 0

  # Group by actual city and calculate top-3 accuracy
  top_k_acc_by_city = df.groupby('actual_city').apply(lambda x: top_k_accuracy(x, 3)).reset_index(name='top3_accuracy')

  print(top_k_acc_by_city)
  ```

- **Interpretation:**

  - This tells you for each actual city, the proportion of times it was predicted within the top 3.

#### **2. Mean Rank per City**

- **Purpose:** Calculate the average rank at which the actual city appears in the predictions, per city.

- **Implementation:**

  ```python
  mean_rank_by_city = df[df['actual_city_rank'].notna()].groupby('actual_city')['actual_city_rank'].mean().reset_index(name='mean_rank')

  print(mean_rank_by_city)
  ```

- **Interpretation:**

  - A lower mean rank indicates better model performance for that city.

---

### **Step 3: Incorporating the City Sequence (Waterfall Information)**

Given the city sequence (`seq = ['nyc', 'miami', 'chicago', 'london', 'none']`), we can analyze how the model's predictions align with this hierarchy.

#### **1. Weighted Accuracy Based on Rank**

- **Purpose:** Assign different weights to predictions based on how far the predicted rank is from the actual city's position in the sequence.

- **Implementation:**

  ```python
  city_sequence = ['nyc', 'miami', 'chicago', 'london', 'none']
  city_sequence_rank = {city: rank for rank, city in enumerate(city_sequence, 1)}

  def calculate_weighted_score(row):
      if row['actual_city_rank'] is None:
          return 0
      actual_seq_rank = city_sequence_rank.get(row['actual_city'], len(city_sequence) + 1)
      pred_seq_rank = city_sequence_rank.get(row['top_cities'][row['actual_city_rank'] - 1], len(city_sequence) + 1)
      rank_diff = abs(actual_seq_rank - pred_seq_rank)
      # Inverse of rank difference as weight (you can adjust the formula as needed)
      weight = 1 / (1 + rank_diff)
      return weight

  df['weighted_score'] = df.apply(calculate_weighted_score, axis=1)

  # Average weighted score
  average_weighted_score = df['weighted_score'].mean()
  print(f"Average Weighted Score: {average_weighted_score}")
  ```

- **Interpretation:**

  - Higher weighted scores indicate better alignment with the city sequence.
  - This metric penalizes predictions that are further away from the actual city's position in the sequence.

#### **2. Mean Reciprocal Rank (MRR)**

- **Purpose:** Evaluate the effectiveness of the model in terms of the position of the actual city in the predicted list.

- **Implementation:**

  ```python
  def reciprocal_rank(rank):
      return 1 / rank if rank is not None else 0

  df['reciprocal_rank'] = df['actual_city_rank'].apply(reciprocal_rank)

  mrr = df['reciprocal_rank'].mean()
  print(f"Mean Reciprocal Rank (MRR): {mrr}")
  ```

- **Interpretation:**

  - MRR ranges between 0 and 1, with higher values indicating better performance.
  - It gives more weight to correct predictions appearing at higher ranks.

---

### **Step 4: Model Correction Strategies**

Given that predicting the actual city at rank 2 is acceptable but rank 3 or lower suggests a need for correction, we can consider the following approaches.

#### **1. Analyzing Misclassifications**

- **Purpose:** Identify patterns in misclassifications to understand why the model predicts the actual city at lower ranks.

- **Implementation:**

  ```python
  # Filter cases where actual city rank is greater than 2
  misclassified = df[df['actual_city_rank'] > 2]

  # Analyze features associated with misclassifications
  misclassified_summary = misclassified.describe()

  print(misclassified_summary)
  ```

- **Interpretation:**

  - This helps identify if certain features or conditions are associated with lower prediction ranks.
  - You can further investigate by grouping or plotting to find insights.

#### **2. Adjusting Model Weights**

- **Purpose:** Modify the model to prioritize certain cities or adjust for biases.

- **Ideas:**

  - **Reweighting Training Data:**
    - Assign higher weights to training samples where the actual city is frequently mispredicted.
  - **Custom Loss Function:**
    - Incorporate the city sequence into the loss function to penalize rank deviations more heavily.
  - **Ensemble Methods:**
    - Combine predictions from multiple models to improve overall accuracy.

---

### **Step 5: Additional Ideas**

#### **1. Cumulative Gain and Lift Charts**

- **Purpose:** Visualize how well the model predicts the actual city across the ranked predictions.

- **Implementation:**

  ```python
  import numpy as np

  # Calculate cumulative gains
  df_sorted = df.sort_values(by='actual_city_rank')
  df_sorted['cumulative_correct'] = np.cumsum(df_sorted['actual_city_rank'] == 1)
  df_sorted['cumulative_total'] = np.arange(1, len(df_sorted) + 1)
  df_sorted['cumulative_gain'] = df_sorted['cumulative_correct'] / df_sorted['cumulative_total']

  # Plot cumulative gain chart
  plt.plot(df_sorted['cumulative_total'], df_sorted['cumulative_gain'])
  plt.xlabel('Number of Predictions')
  plt.ylabel('Cumulative Gain')
  plt.title('Cumulative Gain Chart')
  plt.show()
  ```

- **Interpretation:**

  - The chart helps assess the model's ability to identify the actual city at higher ranks.

#### **2. Precision at K**

- **Purpose:** Calculate the precision of the model at different cut-off ranks.

- **Implementation:**

  ```python
  def precision_at_k(k):
      df['relevant_at_k'] = df['actual_city_rank'].apply(lambda x: 1 if x is not None and x <= k else 0)
      precision = df['relevant_at_k'].sum() / (k * len(df))
      return precision

  # Calculate precision at ranks 1 to 5
  for k in range(1, 6):
      precision = precision_at_k(k)
      print(f"Precision at {k}: {precision}")
  ```

- **Interpretation:**

  - Precision at K provides insight into how many of the top K predictions are relevant (i.e., contain the actual city).

#### **3. Receiver Operating Characteristic (ROC) Curve**

- **Purpose:** Evaluate the trade-off between true positive rate and false positive rate at various thresholds.

- **Implementation:**

  - Since we have multiple classes (cities), we can compute ROC curves for each city using a one-vs-rest approach.

  ```python
  from sklearn.preprocessing import label_binarize
  from sklearn.metrics import roc_curve, auc

  # Binarize the actual city labels
  cities = df['actual_city'].unique()
  y_true = label_binarize(df['actual_city'], classes=cities)
  n_classes = y_true.shape[1]

  # Extract prediction probabilities (assuming you have them)
  # Here, we'll simulate with normalized values from 'mycol1b'

  # Create a matrix of predicted probabilities
  y_score = np.array(df['mycol1b'].tolist())

  # Compute ROC curve and ROC area for each class
  fpr = dict()
  tpr = dict()
  roc_auc = dict()
  for i in range(n_classes):
      fpr[i], tpr[i], _ = roc_curve(y_true[:, i], y_score[:, i])
      roc_auc[i] = auc(fpr[i], tpr[i])

  # Plot ROC curves
  for i in range(n_classes):
      plt.plot(fpr[i], tpr[i], label=f'ROC curve of class {cities[i]} (area = {roc_auc[i]:0.2f})')

  plt.plot([0, 1], [0, 1], 'k--')
  plt.xlabel('False Positive Rate')
  plt.ylabel('True Positive Rate')
  plt.title('Receiver Operating Characteristic')
  plt.legend(loc="lower right")
  plt.show()
  ```

- **Interpretation:**

  - ROC curves help in understanding the performance of the classifier for each city.

---

### **Step 6: Model Improvement Suggestions**

Based on the analysis, you can consider the following strategies to improve the model:

#### **1. Model Retraining with Emphasis on Lower-Ranked Cities**

- **Purpose:** Improve the prediction rank of cities that are frequently predicted at lower ranks.

- **Approach:**

  - **Data Augmentation:**
    - Increase the representation of underperforming cities in the training data.
  - **Feature Engineering:**
    - Create new features that capture unique characteristics of the underperforming cities.
  - **Hyperparameter Tuning:**
    - Adjust model parameters to reduce overfitting to dominant cities.

#### **2. Incorporate Sequential Information**

- **Purpose:** Use the known city sequence to guide the model's predictions.

- **Approach:**

  - **Ordinal Encoding:**
    - Encode the city sequence as ordinal variables to inform the model about the hierarchical order.
  - **Sequential Models:**
    - Utilize models like Hidden Markov Models (HMM) or Recurrent Neural Networks (RNN) if temporal or sequential data is involved.

#### **3. Custom Ranking Loss Function**

- **Purpose:** Modify the loss function to penalize the model more when the actual city is ranked lower.

- **Approach:**

  - **Implement Ranking Loss:**
    - Use loss functions like RankNet or ListNet that are designed for ranking problems.
  - **Sample Weighting:**
    - Assign higher weights to samples where the actual city is ranked lower to force the model to focus on these cases.

---

### **Conclusion**

By conditioning on the actual city and incorporating the known city sequence, you can gain deeper insights into your model's performance and identify areas for improvement. The methods outlined above allow you to:

- **Assess the Model's Ranking Performance:**
  - Using metrics like top-K accuracy, mean rank, and MRR.
- **Analyze Misclassifications:**
  - Identify patterns and adjust the model accordingly.
- **Incorporate Hierarchical Information:**
  - Use the city sequence to inform model predictions and evaluation metrics.
- **Improve the Model:**
  - Through retraining, feature engineering, and loss function adjustments.

### **Next Steps**

- **Implement the Suggested Analyses:**
  - Apply the provided code snippets to your dataset.
- **Evaluate Model Performance:**
  - Use the new metrics to assess where the model performs well and where it needs improvement.
- **Iterate on Model Development:**
  - Based on insights from the analyses, make targeted changes to your model and retrain.

---

### **References**

- **Mean Reciprocal Rank (MRR):** [Wikipedia](https://en.wikipedia.org/wiki/Mean_reciprocal_rank)
- **Precision at K:** [Information Retrieval





Certainly! Let's start from scratch to establish the rank relationship between the predicted cities and the actual cities, using simple statistical measures and plots. We will focus on how the predicted ranks correlate with the true city values and the hit ratio for non-NaN values in `mycol2`. Below are five simple statistical measures or plots that can help quantify this relationship without using regression or machine learning.

---

### **Data Preparation**

First, we need to prepare the data to facilitate our analysis.

1. **Create `mycol1` Map:**

   - Combine `mycol1a` (list of cities) and `mycol1b` (list of values) into a dictionary for each row.

     ```python
     df['mycol1'] = df.apply(lambda x: dict(zip(x['mycol1a'], x['mycol1b'])), axis=1)
     ```

2. **Sort Predicted Cities by Value:**

   - For each row, sort the predicted cities in descending order of their values to obtain a ranked list.

     ```python
     df['sorted_cities'] = df['mycol1'].apply(lambda x: sorted(x.items(), key=lambda item: item[1], reverse=True))
     df['predicted_ranks'] = df['sorted_cities'].apply(lambda x: [city for city, value in x])
     ```

3. **Determine Actual City and Rank:**

   - Assuming you have a column `actual_city` indicating the true city.
   - Find the rank position of the actual city in the predicted ranks.

     ```python
     def get_actual_city_rank(row):
         try:
             return row['predicted_ranks'].index(row['actual_city']) + 1  # Ranks start at 1
         except ValueError:
             return None  # Actual city not in predictions

     df['actual_city_rank'] = df.apply(get_actual_city_rank, axis=1)
     ```

4. **Create Indicator for `mycol2` Non-NaN Values:**

   - Create a binary column indicating whether `mycol2` is non-NaN.

     ```python
     df['mycol2_non_nan'] = df['mycol2'].notna().astype(int)
     ```

---

Now, let's proceed with the five simple statistical measures or plots.

---

### **1. Hit Ratio by Predicted Top City**

**Purpose:** Calculate and visualize the hit ratio (proportion of non-NaN `mycol2`) for each predicted top city. This helps understand how the top predicted city correlates with the occurrence of non-NaN values in `mycol2`.

**Implementation:**

```python
import pandas as pd
import matplotlib.pyplot as plt

# Extract the top predicted city
df['top_predicted_city'] = df['predicted_ranks'].apply(lambda x: x[0] if len(x) > 0 else None)

# Calculate hit ratio by top predicted city
hit_ratio_by_top_city = df.groupby('top_predicted_city')['mycol2_non_nan'].mean().reset_index()

# Plot the hit ratio
plt.figure(figsize=(10, 6))
plt.bar(hit_ratio_by_top_city['top_predicted_city'], hit_ratio_by_top_city['mycol2_non_nan'], color='skyblue')
plt.xlabel('Top Predicted City')
plt.ylabel('Hit Ratio (Proportion of Non-NaN mycol2)')
plt.title('Hit Ratio by Top Predicted City')
plt.xticks(rotation=45)
plt.show()
```

**Interpretation:**

- This bar chart shows the hit ratio for each top predicted city.
- A higher hit ratio indicates that when a particular city is predicted as the top city, `mycol2` is more likely to be non-NaN.
- This helps identify which predicted cities are more reliable in terms of `mycol2` being non-NaN.

---

### **2. Top-K Accuracy**

**Purpose:** Calculate the proportion of times the actual city appears within the top K predicted cities (e.g., K=1, 2, 3). This measures the model's accuracy at different prediction depths.

**Implementation:**

```python
# Function to calculate top-K accuracy
def top_k_accuracy(k):
    df[f'top_{k}_match'] = df.apply(lambda x: 1 if x['actual_city'] in x['predicted_ranks'][:k] else 0, axis=1)
    accuracy = df[f'top_{k}_match'].mean()
    return accuracy

# Calculate top-K accuracy for K=1 to 3
top_k_accuracies = {}
for k in range(1, 4):
    accuracy = top_k_accuracy(k)
    top_k_accuracies[k] = accuracy
    print(f"Top-{k} Accuracy: {accuracy:.2%}")

# Plot the top-K accuracies
plt.figure(figsize=(8, 5))
plt.plot(list(top_k_accuracies.keys()), list(top_k_accuracies.values()), marker='o')
plt.xlabel('K')
plt.ylabel('Accuracy')
plt.title('Top-K Accuracy')
plt.xticks([1, 2, 3])
plt.grid(True)
plt.show()
```

**Interpretation:**

- **Top-1 Accuracy:** Proportion of times the actual city is the top predicted city.
- **Top-2 Accuracy:** Proportion of times the actual city is within the top 2 predicted cities.
- **Top-3 Accuracy:** Proportion of times the actual city is within the top 3 predicted cities.
- The line plot visualizes how the accuracy improves as we consider more top predictions.

---

### **3. Mean Rank of Actual City**

**Purpose:** Compute the average rank at which the actual city appears in the predicted city list. A lower mean rank indicates better overall prediction accuracy.

**Implementation:**

```python
# Filter out rows where actual city rank is not available
df_valid_ranks = df[df['actual_city_rank'].notna()]

# Calculate mean rank
mean_rank = df_valid_ranks['actual_city_rank'].mean()
print(f"Mean Rank of Actual City: {mean_rank:.2f}")

# Calculate mean rank per actual city
mean_rank_per_city = df_valid_ranks.groupby('actual_city')['actual_city_rank'].mean().reset_index()

# Display the mean rank per actual city
print(mean_rank_per_city)
```

**Interpretation:**

- The overall mean rank provides a single metric summarizing how well the model ranks the actual city.
- The mean rank per city helps identify if the model performs better for some cities compared to others.

---

### **4. Histogram of Actual City Ranks**

**Purpose:** Plot a histogram showing the distribution of ranks at which the actual city appears in the predicted city list. This visualizes how frequently the actual city is predicted at each rank.

**Implementation:**

```python
# Plot histogram of actual city ranks
plt.figure(figsize=(10, 6))
plt.hist(df_valid_ranks['actual_city_rank'], bins=range(1, len(df['mycol1a'].iloc[0]) + 2), align='left', rwidth=0.8, color='lightgreen')
plt.xlabel('Rank Position of Actual City')
plt.ylabel('Frequency')
plt.title('Distribution of Actual City Ranks in Predictions')
plt.xticks(range(1, len(df['mycol1a'].iloc[0]) + 1))
plt.show()
```

**Interpretation:**

- The histogram shows how often the actual city appears at each rank position.
- A higher frequency at lower ranks (e.g., rank 1) indicates better model performance.
- If the actual city frequently appears at higher ranks (e.g., rank 4 or 5), it suggests the model may need improvement.

---

### **5. Confusion Matrix**

**Purpose:** Create a confusion matrix between the top predicted city and the actual city. This helps identify where the model's predictions are correct or where specific misclassifications occur.

**Implementation:**

```python
from sklearn.metrics import confusion_matrix
import seaborn as sns

# Prepare data for confusion matrix
df_confusion = df.dropna(subset=['top_predicted_city', 'actual_city'])

# Compute confusion matrix
conf_matrix = confusion_matrix(df_confusion['actual_city'], df_confusion['top_predicted_city'], labels=df['actual_city'].unique())

# Create a DataFrame for the confusion matrix
conf_matrix_df = pd.DataFrame(conf_matrix, index=df['actual_city'].unique(), columns=df['actual_city'].unique())

# Plot the confusion matrix
plt.figure(figsize=(8, 6))
sns.heatmap(conf_matrix_df, annot=True, fmt='d', cmap='Blues')
plt.xlabel('Top Predicted City')
plt.ylabel('Actual City')
plt.title('Confusion Matrix of Top Predicted City vs Actual City')
plt.show()
```

**Interpretation:**

- The confusion matrix shows the counts of correct and incorrect predictions.
- The diagonal elements represent correct predictions where the top predicted city matches the actual city.
- Off-diagonal elements show misclassifications, indicating which cities are commonly confused.
- This helps identify specific areas where the model may be improved.

---

### **Additional Simple Measures and Plots**

In addition to the above five measures, here are some other simple ways to quantify the relationship:

#### **6. Proportion of Non-NaN `mycol2` by Actual City**

**Purpose:** Calculate the hit ratio for non-NaN `mycol2` values for each actual city.

**Implementation:**

```python
# Calculate hit ratio by actual city
hit_ratio_by_actual_city = df.groupby('actual_city')['mycol2_non_nan'].mean().reset_index()

# Plot the hit ratio
plt.figure(figsize=(10, 6))
plt.bar(hit_ratio_by_actual_city['actual_city'], hit_ratio_by_actual_city['mycol2_non_nan'], color='orange')
plt.xlabel('Actual City')
plt.ylabel('Hit Ratio (Proportion of Non-NaN mycol2)')
plt.title('Hit Ratio by Actual City')
plt.xticks(rotation=45)
plt.show()
```

**Interpretation:**

- This bar chart shows how the occurrence of non-NaN `mycol2` values varies by actual city.
- Helps identify if certain cities are associated with higher or lower hit ratios.

---

#### **7. Scatter Plot of Predicted vs Actual City Values**

**Purpose:** Visualize the relationship between the predicted value of the actual city and the presence of non-NaN `mycol2`.

**Implementation:**

```python
# Extract predicted value for actual city
def get_actual_city_value(row):
    return row['mycol1'].get(row['actual_city'], None)

df['actual_city_value'] = df.apply(get_actual_city_value, axis=1)

# Scatter plot
plt.figure(figsize=(10, 6))
plt.scatter(df['actual_city_value'], df['mycol2_non_nan'], alpha=0.6)
plt.xlabel('Predicted Value of Actual City')
plt.ylabel('mycol2 Non-NaN Indicator')
plt.title('Predicted Value of Actual City vs mycol2 Non-NaN')
plt.show()
```

**Interpretation:**

- The scatter plot shows if higher predicted values for the actual city are associated with non-NaN `mycol2`.
- If there's a trend where higher predicted values correspond to `mycol2` being non-NaN, it suggests a relationship between the predicted value and the hit ratio.

---

### **Conclusion**

By using these simple statistical measures and plots, we can effectively quantify the relationship between the predicted city ranks, the actual city values, and the hit ratio for non-NaN `mycol2` values. These methods provide clear, interpretable insights without the need for complex regression models or machine learning techniques.

---

### **Summary of the Five Measures:**

1. **Hit Ratio by Predicted Top City:**
   - Calculates the proportion of non-NaN `mycol2` values for each top predicted city.
   - Visualized using a bar chart.

2. **Top-K Accuracy:**
   - Measures the proportion of times the actual city appears within the top K predicted cities.
   - Visualized using a line plot.

3. **Mean Rank of Actual City:**
   - Computes the average rank position of the actual city in the predicted list.
   - Provides an overall metric and can be broken down per actual city.

4. **Histogram of Actual City Ranks:**
   - Plots the distribution of ranks at which the actual city appears.
   - Helps visualize the frequency of correct predictions at each rank.

5. **Confusion Matrix:**
   - Creates a matrix showing the counts of correct and incorrect predictions between top predicted city and actual city.
   - Visualized using a heatmap for easy interpretation.

---

### **Next Steps**

- **Analyze Results:**
  - Review the plots and statistics to identify patterns or areas for improvement.
  - For example, if certain cities have low hit ratios or are frequently misclassified, consider investigating why.

- **Model Adjustments:**
  - Based on the findings, you might adjust your model or data processing steps to improve accuracy.
  - Focus on features that could help the model better distinguish between cities.

- **Further Exploration:**
  - Consider segmenting the data by other relevant variables to see if relationships differ across groups.
  - You could also perform statistical tests (e.g., chi-square test) to assess the significance of observed differences.

---

Feel free to let me know if you need further clarification or assistance with implementing these measures!









import matplotlib.pyplot as plt
import numpy as np

# Example data
x = np.linspace(0, 400, 400)
y1 = np.sin(x * 0.05) * 20 + 20
y2 = np.cos(x * 0.05) * 20 + 20
y3 = np.sin(x * 0.05 + 0.5) * 20 + 20
y4 = np.cos(x * 0.05 + 0.5) * 20 + 20

plt.figure(figsize=(10, 5))
plt.plot(x, y1, label='HIST vol', linestyle='-', color='#1f77b4', linewidth=2)
plt.plot(x, y2, label='roll 3-mins BV vol', linestyle='--', color='#ff7f0e', linewidth=2)
plt.plot(x, y3, label='roll 30-mins BV vol', linestyle='-.', color='#2ca02c', linewidth=2)
plt.plot(x, y4, label='roll approx. vol prod. adj. rets 30 mins', linestyle=':', color='#d62728', linewidth=2)

font = {'family': 'serif', 'color':  'black', 'weight': 'normal', 'size': 16}
plt.title('Volatility Over Time', fontdict=font)
plt.xlabel('Time (minutes)', fontdict=font)
plt.ylabel('Volatility', fontdict=font)
plt.xticks(fontsize=12, fontname='serif')
plt.yticks(fontsize=12, fontname='serif')
plt.grid(True, linestyle='--', linewidth=0.5, alpha=0.7)
plt.legend(loc='upper left', bbox_to_anchor=(1.05, 1), fontsize=12, frameon=True, shadow=True)
plt.savefig('/mnt/data/color_plot.png', format='png', dpi=300)
plt.show()




import matplotlib.pyplot as plt
import numpy as np

# Example data
x = np.linspace(0, 400, 400)
y1 = np.sin(x * 0.05) * 20 + 20
y2 = np.cos(x * 0.05) * 20 + 20
y3 = np.sin(x * 0.05 + 0.5) * 20 + 20
y4 = np.cos(x * 0.05 + 0.5) * 20 + 20

plt.figure(figsize=(10, 5))
plt.plot(x, y1, label='HIST vol', linestyle='-', marker='o', markersize=5, linewidth=2)
plt.plot(x, y2, label='roll 3-mins BV vol', linestyle='--', marker='s', markersize=5, linewidth=2)
plt.plot(x, y3, label='roll 30-mins BV vol', linestyle='-.', marker='^', markersize=5, linewidth=2)
plt.plot(x, y4, label='roll approx. vol prod. adj. rets 30 mins', linestyle=':', marker='*', markersize=5, linewidth=2)

font = {'family': 'serif', 'color':  'black', 'weight': 'normal', 'size': 16}
plt.title('Volatility Over Time', fontdict=font)
plt.xlabel('Time (minutes)', fontdict=font)
plt.ylabel('Volatility', fontdict=font)
plt.xticks(fontsize=12, fontname='serif')
plt.yticks(fontsize=12, fontname='serif')
plt.grid(True, linestyle='--', linewidth=0.5, alpha=0.7)
plt.legend(loc='upper left', bbox_to_anchor=(1.05, 1), fontsize=12, frameon=True, shadow=True)
plt.savefig('/mnt/data/high_contrast_plot.png', format='png', dpi=300)
plt.show()




#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -lt 3 ]; then
    echo "Usage: $0 <directory> <prefix> <command> [additional command arguments...]"
    exit 1
fi

# Assign arguments to variables
DIRECTORY=$1
PREFIX=$2
COMMAND=$3
shift 3  # Shift the first three arguments so that $@ contains additional command arguments

# Loop through all files in the directory with the specified prefix
for FILE in "$DIRECTORY"/"$PREFIX"*; do
    # Extract the date in yyyymmdd format from the filename using grep
    DATE=$(echo "$FILE" | grep -oP '\d{8}')
    
    if [ -n "$DATE" ]; then
        # Format the date to yyyy-mm-dd
        START_DATE=$(echo "$DATE" | sed 's/\(....\)\(..\)\(..\)/\1-\2-\3/')

        # Calculate the end date (next day) using the `date` command
        END_DATE=$(date -I -d "$START_DATE + 1 day")

        # Run the specified command with start and end dates as parameters
        $COMMAND "$START_DATE" "$END_DATE" "$@"
    else
        echo "No valid date found in file: $FILE"
    fi
done




bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -lt 3 ]; then
    echo "Usage: $0 <directory> <prefix> <command> [additional command arguments...]"
    exit 1
fi

# Assign arguments to variables
DIRECTORY=$1
PREFIX=$2
COMMAND=$3
shift 3  # Shift the first three arguments so that $@ contains additional command arguments

# Loop through all files in the directory with the specified prefix
for FILE in "$DIRECTORY"/"$PREFIX"*; do
    # Extract the date in yyyymmdd format from the filename
   




To create a pilot tar file, when the release to pilot needs to be done, need to first, once the PR is approved, which means one of reviewers switches red color to green, then need to squash all the PRs, so basically go to SIGPY scripts, run python squash and then PR number, once you press it, need to input at the top of VS Code the password, because it will ask for it. Then it will squash it, and after that, once go to PR on Bitbucket, you'll see that there is one more commit, and probably all others are gone, and so can click merge, it will merge it, wait some time, they go to TeamCity, and since it's pilot, don't go to SIGPY and then, let's say, UAT, but go to UAT PROD, because pilot and PROD is in PROD. So there, just near run at the top right, click on three dots, select the latest branch, and it probably will not be master, select just the latest branch and latest commit, click on build, wait some time, maybe 30 seconds. And then go to that build number, it will be a table, click the first number in the first column, then go to build log, step 5, and find put nexus, put slash nexus. Ta-ta-ta-ta-ta, tar.gz file, you'll see that the name of tar file is much more cleaner than in pilot, and then just... So that should be, that tar file should be included in the pilot email, and to check that this tar file works, just copy-paste, don't forget to add HTTP or eq-quant server and port in front of this nexus line, paste it into browser, and if it works, it will download. So tar file, maybe it can ask for verification, keep file or not, once you click in the browser, keep, it will download, if not at all, then probably it doesn't work and maybe link needs to be fixed. So instead of HTTP barclays, it's probably eq-quant something-something and the port. Once you create, once you prepend this server or HTTP line to the whole nexus, ta-ta-ta-tar line, and you check that it works, then paste this in the email. Also there should be jira, and also from tar file you can infer application name, and most importantly, the version of the application is version number that got modified in version.py file, which is... in the main directory of that particular app.
